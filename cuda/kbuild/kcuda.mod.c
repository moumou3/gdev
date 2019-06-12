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
	{ 0x6bbd6f8c, __VMLINUX_SYMBOL_STR(gmalloc_dma) },
	{ 0xb3040323, __VMLINUX_SYMBOL_STR(generic_file_llseek) },
	{ 0x2c59bb51, __VMLINUX_SYMBOL_STR(gref) },
	{ 0xd6ee688f, __VMLINUX_SYMBOL_STR(vmalloc) },
	{ 0x6bf1c17f, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0x3779c96b, __VMLINUX_SYMBOL_STR(gunref) },
	{ 0xa2f67bca, __VMLINUX_SYMBOL_STR(gmemcpy_to_device) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0x9012578e, __VMLINUX_SYMBOL_STR(gfree_dma) },
	{ 0xc912105d, __VMLINUX_SYMBOL_STR(gshmat) },
	{ 0x2f039f6, __VMLINUX_SYMBOL_STR(filp_close) },
	{ 0x9e359463, __VMLINUX_SYMBOL_STR(gshmctl) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0x33e6bc48, __VMLINUX_SYMBOL_STR(gunmap) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0x801f3e1, __VMLINUX_SYMBOL_STR(gmap) },
	{ 0xb45d2fa0, __VMLINUX_SYMBOL_STR(kernel_read) },
	{ 0x54d09c82, __VMLINUX_SYMBOL_STR(gmemcpy_async) },
	{ 0xa262477a, __VMLINUX_SYMBOL_STR(kern_path) },
	{        0, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xef59643c, __VMLINUX_SYMBOL_STR(gshmget) },
	{ 0xc53fa19c, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0x9166fada, __VMLINUX_SYMBOL_STR(strncpy) },
	{ 0xf66d3cab, __VMLINUX_SYMBOL_STR(gopen) },
	{ 0x63afebc1, __VMLINUX_SYMBOL_STR(gbarrier) },
	{ 0x314e1c5a, __VMLINUX_SYMBOL_STR(glaunch) },
	{ 0x521aca61, __VMLINUX_SYMBOL_STR(gquery) },
	{ 0x33c2e0c4, __VMLINUX_SYMBOL_STR(gmemcpy_from_device) },
	{ 0xa34c2b00, __VMLINUX_SYMBOL_STR(gvirtget) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x25b540d3, __VMLINUX_SYMBOL_STR(gclose) },
	{        0, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x4289b77c, __VMLINUX_SYMBOL_STR(gshmdt) },
	{ 0x4f68e5c9, __VMLINUX_SYMBOL_STR(do_gettimeofday) },
	{ 0x4a2e5913, __VMLINUX_SYMBOL_STR(gmalloc) },
	{        0, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xc393ee02, __VMLINUX_SYMBOL_STR(gphysget) },
	{ 0x91aafa35, __VMLINUX_SYMBOL_STR(gsync) },
	{ 0x4b2b6741, __VMLINUX_SYMBOL_STR(gdevice_count) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0xb04e0a1f, __VMLINUX_SYMBOL_STR(gmemcpy) },
	{ 0x760a0f4f, __VMLINUX_SYMBOL_STR(yield) },
	{ 0xb186fbcd, __VMLINUX_SYMBOL_STR(gfree) },
	{ 0xfc6ef6, __VMLINUX_SYMBOL_STR(filp_open) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=gdev";


MODULE_INFO(srcversion, "BA25F9F8EBC73BAEEACA0DA");
