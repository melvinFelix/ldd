

First you have to use : sudo mknod /dev/devicename c 81 0

It creates device file in /dev but you have to give it read/write permission. to do so,

sudo chmod 777 /dev/devicename

Done !!!

