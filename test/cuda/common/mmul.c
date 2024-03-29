#include <cuda.h>
#ifdef __KERNEL__ /* just for measurement */
#include <linux/vmalloc.h>
#include <linux/time.h>
#define printf printk
#define malloc vmalloc
#define free vfree
#define gettimeofday(x, y) do_gettimeofday(x)
#else /* just for measurement */
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#endif

/* tvsub: ret = x - y. */
static inline void tvsub(struct timeval *x, 
						 struct timeval *y, 
						 struct timeval *ret)
{
	ret->tv_sec = x->tv_sec - y->tv_sec;
	ret->tv_usec = x->tv_usec - y->tv_usec;
	if (ret->tv_usec < 0) {
		ret->tv_sec--;
		ret->tv_usec += 1000000;
	}
}

int cuda_test_mmul(unsigned int n, char *path)
{
	int i, j, idx;
	CUresult res;
	CUdevice dev;
	CUcontext ctx;
	CUfunction function;
	CUmodule module;
	CUdeviceptr a_dev, b_dev, c_dev;
	unsigned int *a = (unsigned int *) malloc (n*n * sizeof(unsigned int));
	unsigned int *b = (unsigned int *) malloc (n*n * sizeof(unsigned int));
	unsigned int *c = (unsigned int *) malloc (n*n * sizeof(unsigned int));
	int block_x, block_y, grid_x, grid_y;
	char fname[256];
	struct timeval tv;
	struct timeval tv_total_start, tv_total_end;
	unsigned long total;
	struct timeval tv_h2d_start, tv_h2d_end;
	unsigned long h2d;
	struct timeval tv_d2h_start, tv_d2h_end;
	unsigned long d2h;
	struct timeval tv_exec_start, tv_exec_end;
	struct timeval tv_data_init_start;
	unsigned long data_init;
	struct timeval tv_mem_alloc_start;
	struct timeval tv_conf_kern_start;
	struct timeval tv_close_start;
	unsigned long mem_alloc;
	unsigned long exec;
	unsigned long init_gpu;
	unsigned long configure_kernel;
	unsigned long close_gpu;
	unsigned long data_read;

	unsigned int dummy_b, dummy_c;
		

	/* block_x * block_y should not exceed 512 (16 warps). 
	   fermi allows 1024 threads (32 warps). */
	block_x = n < 16 ? n : 16;
	block_y = n < 16 ? n : 16;
	grid_x = n / block_x;
	if (n % block_x != 0)
		grid_x++;
	grid_y = n / block_y;
	if (n % block_y != 0)
		grid_y++;
	printf("block = (%d, %d)\n", block_x, block_y);
	printf("grid = (%d, %d)\n", grid_x, grid_y);

	gettimeofday(&tv_total_start, NULL);

	res = cuInit(0);
	if (res != CUDA_SUCCESS) {
		printf("cuInit failed: res = %lu\n", (unsigned long)res);
		return -1;
	}

	res = cuDeviceGet(&dev, 0);
	if (res != CUDA_SUCCESS) {
		printf("cuDeviceGet failed: res = %lu\n", (unsigned long)res);
		return -1;
	}

	res = cuCtxCreate(&ctx, 0, dev);
	if (res != CUDA_SUCCESS) {
		printf("cuCtxCreate failed: res = %lu\n", (unsigned long)res);
		return -1;
	}

	sprintf(fname, "%s/mmul_gpu.cubin", path);
	res = cuModuleLoad(&module, fname);
	if (res != CUDA_SUCCESS) {
		printf("cuModuleLoad() failed\n");
		return -1;
	}
	res = cuModuleGetFunction(&function, module, "multiply");
	if (res != CUDA_SUCCESS) {
		printf("cuModuleGetFunction() failed\n");
		return -1;
	}
/*	res = cuFuncSetSharedSize(function, 0x40); /* just random 
	if (res != CUDA_SUCCESS) {
		printf("cuFuncSetSharedSize() failed\n");
		return -1;
	}
*/
	res = cuFuncSetBlockShape(function, block_x, block_y, 1);
	if (res != CUDA_SUCCESS) {
		printf("cuFuncSetBlockShape() failed\n");
		return -1;
	}

	gettimeofday(&tv_mem_alloc_start, NULL);

	/* a[] */
	res = cuMemAlloc(&a_dev, n*n * sizeof(unsigned int));
	if (res != CUDA_SUCCESS) {
		printf("cuMemAlloc (a) failed\n");
		return -1;
	}
	/* b[] */
	res = cuMemAlloc(&b_dev, n*n * sizeof(unsigned int));
	if (res != CUDA_SUCCESS) {
		printf("cuMemAlloc (b) failed\n");
		return -1;
	}
	/* c[] */
	res = cuMemAlloc(&c_dev, n*n * sizeof(unsigned int));
	if (res != CUDA_SUCCESS) {
		printf("cuMemAlloc (c) failed\n");
		return -1;
	}

	gettimeofday(&tv_data_init_start, NULL);

	/* initialize A[] & B[] */
	for (i = 0; i < n; i++) {
		idx = i*n;
		for(j = 0; j < n; j++) {			
			a[idx++] = i;
		}
	}
	for (i = 0; i < n; i++) {
		idx = i*n;
		for(j = 0; j < n; j++) {
			b[idx++] = i;
		}
	}



	gettimeofday(&tv_h2d_start, NULL);
	/* upload a[] and b[] */
	res = cuMemcpyHtoD(a_dev, a, n*n * sizeof(unsigned int));
	if (res != CUDA_SUCCESS) {
		printf("cuMemcpyHtoD (a) failed: res = %lu\n", (unsigned long)res);
		return -1;
	}
	res = cuMemcpyHtoD(b_dev, b, n*n * sizeof(unsigned int));
	if (res != CUDA_SUCCESS) {
		printf("cuMemcpyHtoD (b) failed: res = %lu\n", (unsigned long)res);
		return -1;
	}
	gettimeofday(&tv_h2d_end, NULL);

	gettimeofday(&tv_conf_kern_start, NULL);

	/* set kernel parameters */
	res = cuParamSeti(function, 0, a_dev);	
	if (res != CUDA_SUCCESS) {
		printf("cuParamSeti (a) failed: res = %lu\n", (unsigned long)res);
		return -1;
	}
	res = cuParamSeti(function, 4, a_dev >> 32);
	if (res != CUDA_SUCCESS) {
		printf("cuParamSeti (a) failed: res = %lu\n", (unsigned long)res);
		return -1;
	}
	res = cuParamSeti(function, 8, b_dev);
	if (res != CUDA_SUCCESS) {
		printf("cuParamSeti (b) failed: res = %lu\n", (unsigned long)res);
		return -1;
	}
	res = cuParamSeti(function, 12, b_dev >> 32);
	if (res != CUDA_SUCCESS) {
		printf("cuParamSeti (b) failed: res = %lu\n", (unsigned long)res);
		return -1;
	}
	res = cuParamSeti(function, 16, c_dev);
	if (res != CUDA_SUCCESS) {
		printf("cuParamSeti (c) failed: res = %lu\n", (unsigned long)res);
		return -1;
	}
	res = cuParamSeti(function, 20, c_dev >> 32);
	if (res != CUDA_SUCCESS) {
		printf("cuParamSeti (c) failed: res = %lu\n", (unsigned long)res);
		return -1;
	}
	res = cuParamSeti(function, 24, n);
	if (res != CUDA_SUCCESS) {
		printf("cuParamSeti (c) failed: res = %lu\n", (unsigned long)res);
		return -1;
	}
	res = cuParamSetSize(function, 28);
	if (res != CUDA_SUCCESS) {
		printf("cuParamSetSize failed: res = %lu\n", (unsigned long)res);
		return -1;
	}

	gettimeofday(&tv_exec_start, NULL);
	/* launch the kernel */
	res = cuLaunchGrid(function, grid_x, grid_y);
	if (res != CUDA_SUCCESS) {
		printf("cuLaunchGrid failed: res = %lu\n", (unsigned long)res);
		return -1;
	}
	cuCtxSynchronize();
	gettimeofday(&tv_exec_end, NULL);

	gettimeofday(&tv_d2h_start, NULL);
	/* download c[] */
	res = cuMemcpyDtoH(c, c_dev, n*n * sizeof(unsigned int));
	if (res != CUDA_SUCCESS) {
		printf("cuMemcpyDtoH (c) failed: res = %lu\n", (unsigned long)res);
		return -1;
	}
	gettimeofday(&tv_d2h_end, NULL);

	/* Read back */
	for (i = 0; i < n; i++) {
		idx = i*n;
		for(j = 0; j < n; j++) {			
			dummy_c = c[idx++];
		}
	}



	gettimeofday(&tv_close_start, NULL);

	res = cuMemFree(a_dev);
	if (res != CUDA_SUCCESS) {
		printf("cuMemFree (a) failed: res = %lu\n", (unsigned long)res);
		return -1;
	}
	res = cuMemFree(b_dev);
	if (res != CUDA_SUCCESS) {
		printf("cuMemFree (b) failed: res = %lu\n", (unsigned long)res);
		return -1;
	}
	res = cuMemFree(c_dev);
	if (res != CUDA_SUCCESS) {
		printf("cuMemFree (c) failed: res = %lu\n", (unsigned long)res);
		return -1;
	}

	res = cuModuleUnload(module);
	if (res != CUDA_SUCCESS) {
		printf("cuModuleUnload failed: res = %lu\n", (unsigned long)res);
		return -1;
	}

	res = cuCtxDestroy(ctx);
	if (res != CUDA_SUCCESS) {
		printf("cuCtxDestroy failed: res = %lu\n", (unsigned long)res);
		return -1;
	}

	free(a);
	free(b);
	free(c);

	gettimeofday(&tv_total_end, NULL);


	tvsub(&tv_mem_alloc_start, &tv_total_start, &tv);
	init_gpu = tv.tv_sec * 1000000 + (unsigned long) tv.tv_usec;

	tvsub(&tv_data_init_start, &tv_mem_alloc_start, &tv);
	mem_alloc = tv.tv_sec * 1000000 + (unsigned long) tv.tv_usec;

	tvsub(&tv_h2d_start, &tv_data_init_start, &tv);
	data_init = tv.tv_sec * 1000000 + (unsigned long) tv.tv_usec;

	tvsub(&tv_h2d_end, &tv_h2d_start, &tv);
	h2d = tv.tv_sec * 1000000 + (unsigned long) tv.tv_usec;

	tvsub(&tv_exec_start, &tv_conf_kern_start, &tv);
	configure_kernel = tv.tv_sec * 1000000 + (unsigned long) tv.tv_usec;

	tvsub(&tv_exec_end, &tv_exec_start, &tv);
	exec = tv.tv_sec * 1000000 + (unsigned long) tv.tv_usec;

	tvsub(&tv_d2h_end, &tv_d2h_start, &tv);
	d2h = tv.tv_sec * 1000000 + (unsigned long) tv.tv_usec;

	tvsub(&tv_close_start, &tv_d2h_end, &tv);
	data_read = tv.tv_sec * 1000000 + (unsigned long) tv.tv_usec;

	tvsub(&tv_total_end, &tv_close_start, &tv);
	close_gpu = tv.tv_sec * 1000000 + (unsigned long) tv.tv_usec;

	tvsub(&tv_total_end, &tv_total_start, &tv);
	total = tv.tv_sec * 1000000 + (unsigned long) tv.tv_usec;

	printf("Init: %lu\n", init_gpu);
	printf("MemAlloc: %lu\n", mem_alloc);
	printf("DataInit: %lu\n", data_init);
	printf("HtoD: %lu\n", h2d);
	printf("KernConf: %lu\n", configure_kernel);
	printf("Exec: %lu\n", exec);
	printf("DtoH: %lu\n", d2h);
	printf("DataRead: %lu\n", data_read);
	printf("Close: %lu\n", close_gpu);
	printf("Total: %lu\n", total);


	return 0;
}
