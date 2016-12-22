#include "itronix.h"

void add(int a,int b) {
	int sum = 0;
	sum = a+b;
	printk(KERN_INFO "sum of two numbers is %d\n",sum);
}
