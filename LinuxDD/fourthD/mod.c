#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>

static dev_t first;

static int __init hello_init(void)
{
	int ret;
	printk(KERN_INFO "Hello world: first registered");
	if((ret = alloc_chrdev_region(&first, 0, 4, "hello_driver")) < 0)
	{
		return ret;
	}
	printk(KERN_INFO "[Major, Minor]:=> [%d,%d]\n", MAJOR(first), MINOR(first));
	return 0;
}

static void __exit hello_exit(void)
{
	unregister_chrdev_region(first, 4);
	printk(KERN_INFO "Bye World: unregistered");
}

module_init(hello_init);
module_exit(hello_exit);


