#include <linux/kernel.h>
#include <linux/module.h>

int add(int a,int b);

int add(int a,int b) {
	return a+b;
}

EXPORT_SYMBOL_GPL(add);

int init_module(void) {
	printk(KERN_INFO "\n");
	return 0;
}

void cleanup_module(void) {
	printk(KERN_INFO "driver removed \n");
}

MODULE_LICENSE("GPL");
