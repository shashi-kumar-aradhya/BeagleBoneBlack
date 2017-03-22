/*
#define PUT32(addr, value) (*(volatile unsigned int *)addr=value)
#define GET32(addr) (*(volatile unsigned int *)addr)
*/
#define PUT32		(volatile unsigned int *)
#define GET32	*(volatile unsigned int *)

#define GPIO1_BASE		 0X4804C000
#define GPIO_OE  		 0X134
#define GPIO_SETDATAOUT 	 0X194

#define CM_PER_BASE 		 0x44e00000
#define CM_PER_GPIO1		 0xac


void _main(void)
{


	volatile unsigned int ra;

	(*PUT32(CM_PER_BASE+CM_PER_GPIO1)) = 1<<18 | 2;
	ra = GET32(GPIO1_BASE+GPIO_OE);
	ra &= ~(1<<21);
	(*PUT32(GPIO1_BASE+GPIO_OE)) = ra;

	(*PUT32(GPIO1_BASE+GPIO_SETDATAOUT)) = 1<<21;
}
