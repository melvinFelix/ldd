#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>

#define simple_major 300
#define MINORNO  0
#define CHAR_DEV_NAME "ITRONIX"

static dev_t first; // Global variable for the first device number

static int __init hello_init(void) /* Constructor */
{
	 int result;

         first = MKDEV(simple_major, 0);

        /* Figure out our device number. */
        if((result = register_chrdev_region(first, 1,CHAR_DEV_NAME)) < 0);	
	{	
         return result;
        }	
	
}

       
static void __exit hello_exit(void) /* Destructor */
{
	unregister_chrdev_region(first, 1);
	printk(KERN_INFO "Bye World:  unregistered");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("KARAN ARORA");
MODULE_DESCRIPTION(" First Character Driver");
