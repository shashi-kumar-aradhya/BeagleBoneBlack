#include "uart.h"
#include "uart_console_header.h"

void Uart0_Reset() 
{
	unsigned int temp = GET32(UART0+SYSC);
	temp |= 0x2;
	PUT32(UART0+SYSC, temp);				//Uart soft reset
	while(((GET32(UART0+SYSS)) & 0x1) == 0);		//Wait till reset is complete

	temp = GET32(UART0+SYSC);
	temp |= (0x1 << 0x3);
	PUT32(UART0+SYSC, temp);				//No idle

	while(((GET32(UART0+LSR) & 0x40) !=0x40));    		// wait for txfifo to be empty

	/* UART Interrupt Enable Register */
	PUT32(UART0+IER, 0);					/*Disable uart interrupts*/

	PUT8(UART0+MDR1, 0x7);        			// Disable modeselect (default)
}



int UART_init(unsigned int baudrate, STOP_BIT_t stopBit, PARITY_BIT_t parity, FLOW_flowControl) 
{
	//UART mux config
	Uart0_Mux();

	//Init clock and muxing of pins
	Init_UART0_Clk();

	//Uart soft reset
	Uart0_Reset();
}
void UART_putc(char c);
char UART_getc();
int UART_putstring(char *str, unsigned int length);
int UART_getstring(char *buf, unsigned int length);
