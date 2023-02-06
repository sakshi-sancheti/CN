#include <linux/module.h>
#include <linux/init.h>

/*meta information*/

MODULE_LICENSE("GPL");
MODULE_AUTHOR("sakshi GNU/linux");
MODULE_DESCRIPTION("A hello world LKM");

//this function is called when module is loaded in the kernel

static int __init ModuleInit(void)
{  printk("hello kernel!\n");
	return 0;
}

//this function is called when module is removed from the kernel
static void __exit ModuleExit(void)
{
	printk("Goodbye kernel!\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);

