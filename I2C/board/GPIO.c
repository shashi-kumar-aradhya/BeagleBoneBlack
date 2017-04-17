#include "gpio.h"
//#include "clock.h"
void LED_init(void)
{


	volatile unsigned int ra;

	PUT32(CM_PER_BASE+CM_PER_GPIO1, 1<<18 | 2);
	ra = GET32(GPIO1_BASE+GPIO_OE);
	ra &= ~(1<<21);
	PUT32(GPIO1_BASE+GPIO_OE, ra);

	PUT32(GPIO1_BASE+GPIO_SETDATAOUT, 1<<21);
}
