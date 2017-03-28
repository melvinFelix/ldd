#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>

#include <linux/kernel.h> /* printk() */
#include <linux/fs.h>     /* everything... */
#include <linux/errno.h>  /* error codes */
#include <linux/types.h>  /* size_t */
#include <linux/vmalloc.h>
#include <linux/genhd.h>
#include <linux/blkdev.h>
#include <linux/hdreg.h>


int myblkdev_major = 0;
static int __init myblkdev_init(void)
{
if ((myblkdev_major = register_blkdev(myblkdev_major,"myblkdev")) <= 0) 
	{
		return -EIO;
	}
else
	{
		printk(KERN_ALERT "Device registered Successfully..\n");
	}
return 0;
}

static void __exit myblkdev_exit(void)
{
	unregister_blkdev(myblkdev_major, "myblkdev");
	printk(KERN_ALERT "Device unregister Successfully..\n");
}

module_init(myblkdev_init);
module_exit(myblkdev_exit);
MODULE_LICENSE("GPL");

