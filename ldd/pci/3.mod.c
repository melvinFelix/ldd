#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
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
	{ 0x5eadf54a, "module_layout" },
	{ 0x561bc67, "unregister_netdev" },
	{ 0x18f64c13, "free_netdev" },
	{ 0xe42cc6e1, "register_netdev" },
	{ 0x29eed280, "alloc_netdev_mqs" },
	{ 0x16305289, "warn_slowpath_null" },
	{ 0x6194b31c, "consume_skb" },
	{ 0x1dd4c8e8, "ether_setup" },
	{ 0x50eedeb8, "printk" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "AD8F5713769B7A2C3B6298C");
