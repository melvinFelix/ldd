#include "itronix.h"

int init_module(void) {
	add(5,10);

	struct task_struct *task;

	for_each_process(task) {
		printk("Process name = %s\t PID=%d\t PS = %ld\n",task->comm,task->pid,task->state);
	}
	return 0;
}


void cleanup_module(void) {
	printk(KERN_ALERT "the driver is removed\n");
}
