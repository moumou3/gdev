# Makefile
TARGET	= user_test
CC	= gcc
NVCC	= nvcc -arch sm_20 -cubin
LIBS	= -lucuda -lgdev
CFLAGS	= -g -L /usr/local/gdev/lib64 -I /usr/local/gdev/include

all:
	$(NVCC) -o madd_gpu.cubin madd_gpu.cu
	gcc -o $(TARGET) $(CFLAGS) main.c madd.c $(LIBS)

clean:
	rm -f $(TARGET) *.cubin ./*~
