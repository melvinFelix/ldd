#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/usb.h>

static int pen_probe(struct usb_interface *interface,const struct usb_device_id *id)
{
 printk(KERN_INFO "new pen drive (%04X:%04X) plugged in\n",id ->idVendor,id ->idProduct);
 printk(KERN_INFO "CONGRATS buddy!!! usb plugged successfully\n");
 return 0;
}

static int pen_disconnect(struct usb_interface *interface)
{ 
 printk(KERN_INFO "YOUR pendrive is removed \n");
 printk(KERN_INFO "good bye,visit again \n");
}

static struct usb_device_id pen_table[]=
{
 {USB_DEVICE(0x03f0,0x3640)},
{}

};
MODULE_DEVICE_TABLE(usb,pen_table);

static struct usb_driver pen_driver =
{
 .name="MY pendrive",
 .id_table = pen_table,
 .probe = pen_probe,
 .disconnect =pen_disconnect,
};
static int __init pen_init(void)
{
 return usb_register(&pen_driver);
}

static void __exit pen_exit(void)
{
 usb_deregister(&pen_driver);

}

module_init(pen_init);
module_exit(pen_exit);
MODULE_LISCENCE("GPL");

