#include <linux/init.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/blkdev.h>
#include <linux/genhd.h>
#include <linux/hdreg.h>

#define block_major 0
#define minor_no 0
#define BLOC_DEV_NAME "ITERATIONS"

//static dev_t first;

static int __init hello_init(void) {
	int result;

	//first = MKDEV(block_major, 0);

	if((result = register_blkdev(block_major,BLOC_DEV_NAME)) <= 0) {
		return -EIO;
	}else {
		printk(KERN_INFO "driver registered\n");	
	}

}

static void __exit hello_exit(void) {
	unregister_blkdev(block_major,BLOC_DEV_NAME);
	printk(KERN_INFO "Bye World: unregistered\n");
}

module_init(hello_init);
module_exit(hello_exit);
