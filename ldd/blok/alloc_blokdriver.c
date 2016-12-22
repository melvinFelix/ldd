#include <linux/module.h>
#include<linux/init.h>
#include<Linux/moduleparam.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include<linux/blkdev.h>
#include<linux/genhd.h>
#include<linux/hdreg.h>

//static dev_t first; // Global variable for the first device number
int helloblok_major = 0;
static int __init helloblok_init(void) /* Constructor */
{
	int ret;

	printk(KERN_INFO "Hello world: first registered");
	if ((helloblok_major = register_blkdev(helloblok_major ,"helloblok")) <= 0)
	{
		return -EIO;
	}
	else
        {
        printk (KERN_INFO"driver successful"); 
        }
	return 0;
}

static void __exit helloblok_exit(void) /* Destructor */
{
	unregister_blkdev(helloblok_major,"helloblok");
	printk(KERN_INFO "Bye World:  unregistered");
}

module_init(helloblok_init);
module_exit(helloblok_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("KARAN ARORA");
MODULE_DESCRIPTION(" First blok Driver");
