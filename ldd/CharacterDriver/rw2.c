#include <linux/module.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("READ WRITE");
MODULE_AUTHOR("ER.Karan Arora");

static char msg[100]={0};
static short readpos=0;
static int times=0;
static char mymsg[100]={0};

static int dev_open(struct inode *, struct file *);
static int dev_rls(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);

static struct file_operations fops=
{
	.read=dev_read,
	.open=dev_open,
	.write=dev_write,
	.release=dev_rls,
};

int init_module(void)
{
	int t = register_chrdev(250,"itronix",&fops);
	if(t<0)
		printk(KERN_ALERT "Device registraion failed..\n");
	else
		printk(KERN_ALERT "Device registered..\n");
	return t;
}

void cleanup_module(void)
{
	unregister_chrdev(250,"itronix");
}

static int dev_open(struct inode *inod, struct file *fil)
{
	times++;
	printk(KERN_ALERT " Device opened %d times\n",times);
	return 0;
}

static ssize_t dev_read(struct file *filp, char *buff, size_t len, loff_t *off)
{
	short count = 0;
	while(len && (msg[readpos]!=0))
	{

		put_user(msg[readpos],buff++);
		count++;
		len--;
		readpos++;
	}
		printk(KERN_INFO "reading %s\n",msg);
		return count;
}

static ssize_t dev_write(struct file *filp, const char *buff, size_t len, loff_t *off)
{
	short ind = len-1;
	short mylen = len;
	short count = 0;
	int i,j=0;
	memset(msg,0,100);
	readpos=0;
	while(len>0)
	{
		msg[count++] = buff[ind--];
		len--;
	}
	
	for(i=0;i<mylen;i++)
	{
		printk(KERN_INFO "Mymsg is %c\n",msg[i]);
		if(msg[i]=='a' || msg[i]=='e'|| msg[i]=='i' || msg[i]=='o' || msg[i]=='u')
			{
				mymsg[j]=msg[i];
				printk(KERN_INFO "In the loop %c\n",mymsg[j]);
				j++;
			}
	}
	printk(KERN_INFO "Mymsg latest  %s\n",mymsg);
	printk(KERN_INFO "writing %s\n",buff);
	

	return count;
}

static int dev_rls(struct inode *inod,struct file *fil)
{
	printk(KERN_ALERT "Device closed\n");
	return 0;
}

