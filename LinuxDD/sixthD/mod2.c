#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include "func_prot.h"

int usage_init(void) {
	printk("USAGE MODE LOADED \n");
	printk("sum = %d\n",add(2,3));
	return 0;
}

void usage_exit(void) {
	printk("usage module unloaded \n");
}

module_init(usage_init);
module_exit(usage_exit);

MODULE_LICENSE("GPL");
