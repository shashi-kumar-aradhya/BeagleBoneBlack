#include "uart.h"
#include "uart_console_header.h"

#define PUT32 (volatile unsigned int *)
#define GET32 *(volatile unsigned int *)
/*	(*PUT32(CM_PER_BASE+CM_PER_GPIO1)) = 1<<18 | 2;
	ra = GET32(GPIO1_BASE+GPIO_OE);
*/
int UART_init(unsigned int baudrate, STOP_BIT_t stopBit, PARITY_BIT_t parity, FLOW_flowControl) 
{
	//UART mux config
	Uart0_Mux();
	//Init clock and muxing of pins
	Init_UART0_Clock();
}
void UART_putc(char c);
char UART_getc();
int UART_putstring(char *str, unsigned int length);
int UART_getstring(char *buf, unsigned int length);
