#ifneq ($(KERNELRELEASE),)

   obj-m := 3.o
   //ramdriver-y := ram_block.o ram_device.o partition.o

#else

KERNELDIR ?= /lib/modules/$(shell uname -r)/build

PWD := $(shell pwd)

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean 

#endif

