extern void PUT32(unsigned int address, unsigned int value);
extern unsigned int GET32(unsigned int address);

#define GPIO1_BASE	0x4804C000
#define	GPIO_SYSCONFIG	0x10
#define	GPIO_SYSSTATUS	0x114
#define GPIO_OE		0x134
#define	GPIO_CLRDATA	0x190
#define GPIO_SETDATA	0x194

#define	CM_PER_BASE	0x44e00000
#define	CM_PER_GPIO1	0XAC

#define	TIME	500000

void _main(void)
{
	volatile unsigned int ra;
	PUT32(CM_PER_BASE+CM-PER_GPIO1, 1<<18 | 2);
	ra = GET32(GPIO1_BASE+GPIO_OE);
	ra &= ~(15<<21);
	PUT32(GPIO1_BASE+GPIO1_OE,ra);
	for(;;)
	{
		PUT32(GPIO1_BASE+GPIO_SETDATAOUT, (15<<21);
