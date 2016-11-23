#include <linux/kernel.h>
#include <linux/init.h> 
#include <linux/module.h> 
#include <linux/delay.h>
#include <linux/gpio.h>

#define LED_GPIO 258
#define GPIO_LOW 0
#define GPIO_HIGH 1
static void mos_short(void)
{
	gpio_set_value(LED_GPIO,GPIO_LOW);
	mdelay(500);
	gpio_set_value(LED_GPIO,GPIO_HIGH);
	mdelay(500);
	printk("mos short\n");
}

static void mos_long(void)
{
	gpio_set_value(LED_GPIO,GPIO_LOW);
	mdelay(1000);
	gpio_set_value(LED_GPIO,GPIO_HIGH);
	mdelay(1000);
	printk("mos long\n");
}


static int __init hello_init(void)
{
    int i;
    for(i=0;i<=10;i++)
    {
	//S
	    mos_short();
	    mos_short();
	    mos_short();
	    mdelay(500);
	//O
	    mos_long();
	    mos_long();
	    mos_long();
	    mdelay(500);
	//S
	    mos_short();
	    mos_short();
	    mos_short();
	    mdelay(1000);
	printk("~~~~~~~~~~~~~~~~~~~~~~~~SOS~~~~~~~~~~~~~~~~~~~~~~~~ %d\n",i);
	}
    return 0;
}

static void __exit hello_exit(void)
{
    printk("Exit Hello world\n");
}

subsys_initcall(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("sai <271319925@qq.com>");
MODULE_DESCRIPTION("Firefly hello driver");
MODULE_LICENSE("GPL");
/*
    ret = gpio_request(LED_GPIO, "led");

*/

/*init
    int i;
    for(i=0;i<=10;i++)
    {
	printk("~~~~~~~~~~~~~~~~~~~~~~~~Hello world~~~~~~~~~~~~~~~~~~~~~~~~ %d\n",i);
	mdelay(1000);
	}
    return 0;
*/


/*flash 10s
    int i;
    for(i=0;i<=10;i++)
    {
	printk("~~~~~~~~~~~~~~~~~~~~~~~~Hello world~~~~~~~~~~~~~~~~~~~~~~~~ %d\n",i);
	gpio_set_value(LED_GPIO,GPIO_LOW);
	printk("the led lever is : %d\n",gpio_get_value(LED_GPIO));		
	mdelay(500);
        gpio_set_value(LED_GPIO,GPIO_HIGH);
	printk("the led lever is : %d\n",gpio_get_value(LED_GPIO));
	mdelay(500);
	}
    return 0;
*/
/*
    int i;
    for(i=0;i<=10;i++)
    {
	//S
	    mos_short();
	    mos_short();
	    mos_short();
	    mdelay(500);
	//O
	    mos_long();
	    mos_long();
	    mos_long();
	    mdelay(500);
	//S
	    mos_short();
	    mos_short();
	    mos_short();
	    mdelay(1000);
	printk("~~~~~~~~~~~~~~~~~~~~~~~~SOS~~~~~~~~~~~~~~~~~~~~~~~~ %d\n",i);
	}
    return 0;
*/
