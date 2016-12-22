#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/stat.h>

static char* whom = "world";
static int howmany = 75;
static bool status = 1;
static int a[2] = {1,2};
static int arr_argc=0;

module_param(howmany,int,S_IRUSR | S_IWUSR);
module_param(whom,charp,S_IRUSR);
module_param(status,bool,S_IRUSR);
module_param_array(a,int,&arr_argc,S_IRUSR | S_IWUSR);

int init_module(void) {
	int i;
	printk("the value is %d\n",howmany);
	printk("the value is %s\n",whom);
	printk("the value is %d\n",status);
	for(i = 0;i<2;++i) {
		printk("the array is %d \n",a[i]);
	}
	printk("the number of arguments passed in the array is %d\n",arr_argc);
	return 0;
}


void cleanup_module(void) {
	printk(KERN_ALERT "the driver is removed\n");
}
