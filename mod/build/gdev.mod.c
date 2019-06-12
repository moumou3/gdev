#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xc0461f48, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x57fae731, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0xde1a9923, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x9d792808, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x6365ac5d, __VMLINUX_SYMBOL_STR(gdev_drv_getdrm) },
	{ 0x44aca3f, __VMLINUX_SYMBOL_STR(gdev_drv_bo_unmap) },
	{ 0x75033ef6, __VMLINUX_SYMBOL_STR(gdev_drv_chan_alloc) },
	{ 0xd6ee688f, __VMLINUX_SYMBOL_STR(vmalloc) },
	{ 0x6bf1c17f, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0x9572ca6b, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0xd5b1f839, __VMLINUX_SYMBOL_STR(gdev_drv_write) },
	{ 0x224e47d3, __VMLINUX_SYMBOL_STR(gdev_drv_vspace_free) },
	{ 0xd0ee38b8, __VMLINUX_SYMBOL_STR(schedule_timeout_uninterruptible) },
	{ 0xe95109e9, __VMLINUX_SYMBOL_STR(gdev_drv_bo_alloc) },
	{ 0xc7c749c8, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0x20000329, __VMLINUX_SYMBOL_STR(simple_strtoul) },
	{ 0x75736927, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0x63e5921d, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0xb0390c8d, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x8fdf772a, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0xb5b8660a, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x484c8f2d, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0x3be2650b, __VMLINUX_SYMBOL_STR(gdev_drv_getdevice) },
	{ 0x90fa28, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0xe55103bc, __VMLINUX_SYMBOL_STR(gdev_drv_vspace_alloc) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{        0, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0xb95a8871, __VMLINUX_SYMBOL_STR(PDE_DATA) },
	{ 0x3f5c6471, __VMLINUX_SYMBOL_STR(del_timer_sync) },
	{ 0xf1dc102, __VMLINUX_SYMBOL_STR(gdev_drv_getparam) },
	{ 0x1836131, __VMLINUX_SYMBOL_STR(proc_mkdir) },
	{ 0x3744cf36, __VMLINUX_SYMBOL_STR(vmalloc_to_pfn) },
	{ 0x1916e38c, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0xc53fa19c, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x87f0d674, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0xc186a3ee, __VMLINUX_SYMBOL_STR(kthread_stop) },
	{ 0xec413716, __VMLINUX_SYMBOL_STR(gdev_drv_bo_map) },
	{        0, __VMLINUX_SYMBOL_STR(phys_base) },
	{ 0x8117cc30, __VMLINUX_SYMBOL_STR(gdev_drv_read) },
	{ 0x531b604e, __VMLINUX_SYMBOL_STR(__virt_addr_valid) },
	{ 0x7db8d508, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0xf1969a8e, __VMLINUX_SYMBOL_STR(__usecs_to_jiffies) },
	{ 0x6dc6dd56, __VMLINUX_SYMBOL_STR(down) },
	{ 0xa19fcfd1, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0xfa5bcf35, __VMLINUX_SYMBOL_STR(mod_timer) },
	{ 0x473e1e3e, __VMLINUX_SYMBOL_STR(gdev_drv_read32) },
	{ 0x8ef51316, __VMLINUX_SYMBOL_STR(gdev_drv_bo_bind) },
	{ 0xafec7662, __VMLINUX_SYMBOL_STR(gdev_drv_subch_alloc) },
	{ 0xefcaf4ed, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x7cd8d75e, __VMLINUX_SYMBOL_STR(page_offset_base) },
	{ 0x78764f4e, __VMLINUX_SYMBOL_STR(pv_irq_ops) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0xe5815f8a, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irq) },
	{ 0x211f68f1, __VMLINUX_SYMBOL_STR(getnstimeofday64) },
	{ 0x3ecd9d41, __VMLINUX_SYMBOL_STR(gdev_drv_getaddr) },
	{ 0x78e66086, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{        0, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xe617be17, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x680ec266, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0xd963c634, __VMLINUX_SYMBOL_STR(sched_setscheduler) },
	{ 0xb3f7646e, __VMLINUX_SYMBOL_STR(kthread_should_stop) },
	{ 0x2392344f, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0xbeab7abd, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0x9c55cec, __VMLINUX_SYMBOL_STR(schedule_timeout_interruptible) },
	{ 0xd677969a, __VMLINUX_SYMBOL_STR(gdev_drv_bo_unbind) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x69ee32ac, __VMLINUX_SYMBOL_STR(remap_pfn_range) },
	{ 0xac1c068e, __VMLINUX_SYMBOL_STR(gdev_drv_bo_free) },
	{        0, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x78e739aa, __VMLINUX_SYMBOL_STR(up) },
	{ 0x16370c38, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xd12da0a2, __VMLINUX_SYMBOL_STR(gdev_drv_write32) },
	{ 0x436c2179, __VMLINUX_SYMBOL_STR(iowrite32) },
	{        0, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x298d728b, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x1ce15bb9, __VMLINUX_SYMBOL_STR(gdev_drv_subch_free) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0xe484e35f, __VMLINUX_SYMBOL_STR(ioread32) },
	{ 0xa8b6fd2d, __VMLINUX_SYMBOL_STR(gdev_drv_chan_free) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=nouveau";


MODULE_INFO(srcversion, "97053A5344874FDAA40B7F5");
