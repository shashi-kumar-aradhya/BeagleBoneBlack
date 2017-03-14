#define PUT32 (volatile unsigned int *)
#define GET32 *(volatile unsigned int *)


//#define	CM_PER_GPIO1_CLKCTRL	 0x44e000AC
//#define	GPIO1_OE		 0x4804C134
//#define	GPIO1_SETDATAOUT	 0x4804C194
#define GPIO1_BASE		 0X4804C000
#define GPIO_OE  		 0X134
#define GPIO_SETDATAOUT 	 0X194
//#define GPIO_CLRDATAOUT 	 0X190

#define CM_PER_BASE 		 0x44e00000
#define CM_PER_GPIO1		 0xac


void _main(void)
{


	volatile unsigned int ra;
	(*PUT32(CM_PER_BASE+CM_PER_GPIO1)) = 1<<18 | 2;
	ra = GET32(GPIO1_BASE+GPIO_OE);
	ra &= ~(1<<21);
	(*PUT32(GPIO1_BASE+GPIO_OE)) = ra;

	//	for(;;)
	//	{
	(*PUT32(GPIO1_BASE+GPIO_SETDATAOUT)) = (1<<21);
	//		for(ra = 0; ra < TIME; ra ++);
	//		(*PUT32(GPIO1_BASE+GPIO_CLRDATAOUT)) = 1<<21;

	//		for(ra = 0; ra < TIME; ra++);
	//	}
	return;

}
