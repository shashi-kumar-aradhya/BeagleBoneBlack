#include "uart.h"
#include "uart_console_header.h"
#include "clock.h"
#include "types.h"

#define GPIO1_BASE		 0X4804C000
#define GPIO_OE  		 0X134
#define GPIO_SETDATAOUT 	 0X194

#define CM_PER_BASE 		 0x44e00000
#define CM_PER_GPIO1		 0xac


void _main(void)
{


	volatile unsigned int ra;
	char a = 'a';

	PUT32(CM_PER_BASE+CM_PER_GPIO1, 1<<18 | 2);
	ra = GET32(GPIO1_BASE+GPIO_OE);
	ra &= ~(1<<21);
	PUT32(GPIO1_BASE+GPIO_OE, ra);

	PUT32(GPIO1_BASE+GPIO_SETDATAOUT, 1<<21);

	UART_init(115200,STOP1,PARITY_NONE,FLOW_OFF);
	while(a != 'z') {
	UART_putC(a);
	a++;
	}
//	UART_putString("UART0 Initialized...\n",21);
/*
	while(1)
	{   
		UART_putC(UART_getC());
	}   
*/

}
