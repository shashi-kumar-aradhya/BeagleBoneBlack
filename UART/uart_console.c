#include "uart.h"
#include "uart_console_header.h"

#define PUT32 (volatile unsigned int *)
#define GET32 *(volatile unsigned int *)
/*	(*PUT32(CM_PER_BASE+CM_PER_GPIO1)) = 1<<18 | 2;
	ra = GET32(GPIO1_BASE+GPIO_OE);
*/

void UART_putc(char c);
char UART_getc();
int UART_putstring(char *str, unsigned int length);
int UART_getstring(char *buf, unsigned int length);
