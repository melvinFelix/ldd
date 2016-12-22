obj-m := func_module.o

func_module-objs := module_param.o add.o

KVERSION =$(shell uname -r)

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean


