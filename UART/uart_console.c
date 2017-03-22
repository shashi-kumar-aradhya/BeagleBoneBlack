#include "uart.h"
#include "uart_console_header.h"
#include "clock.h"
#include "control_module.h"
void Uart0_Reset(unsigned int baudrate) 
{
	unsigned int temp = GET32(UART0+SYSC);
	temp |= 0x2;
	PUT32(UART0+SYSC, temp);				//Uart soft reset
	while(((GET32(UART0+SYSS)) & 0x1) == 0);		//Wait till reset is complete

	temp = GET32(UART0+SYSC);
	temp |= (0x1 << 0x3);
	PUT32(UART0+SYSC, temp);				//No idle

	while(((GET32(UART0+LSR) & 0x40) !=0x40));    		// wait for txfifo to be empty

	float div = 48000000.0/(16.0*(float)baudrate);
	unsigned int intdiv = (unsigned int) div;
	/* UART Interrupt Enable Register */
	PUT8(UART0+IER, 0);					/*Disable uart interrupts*/
	PUT8(UART0+MDR1,0x7);        // Disable modeselect (default) TRM table 19-50
	PUT8(UART0+LCR,~(0x7C));    // divisor latch enable, access DLL DHL, set uart as 8bit
	PUT8(UART0+RHR,0);          // DLL = 0
	PUT8(UART0+IER,0);          // DHL = 0
	PUT8(UART0+LCR,0x3);        // set uart as 8bit
	PUT8(UART0+MCR,0x3);        // force /rts & /drt to active (low) (?!)
	PUT8(UART0+FCR,0x7);        // clear rx&tx FIFOs, and enables them (each 64 bytes deep)
	PUT8(UART0+LCR,~(0x7C));    // divisor latch enable, access DLL DHL, set uart as 8bit
	PUT8(UART0+RHR,intdiv&0xFF);          // DLL = 0
	PUT8(UART0+IER,(intdiv>>8)&0x3F);          // DHL = 0

	//            PUT8(uart_base+0x00,26);         // DLL/DHL value for 115200
	PUT8(UART0+LCR,0x3);        // set uart as 8 bit
	PUT8(UART0+MDR1,0);          // uart 16x oversampling
}



void UART_init(unsigned int baudrate, STOP_BIT_t stopBit, PARITY_BIT_t parity, FLOW_t flowControl) 
{
	//UART mux config
	Uart0_Mux();

	//Init clock and muxing of pins
	Init_UART0_Clk();

	//Uart soft reset
	Uart0_Reset(baudrate);
}

void UART_putC( char c)
{
	while((GET8(UART0+0x14)&0x20)!=0x20);   //wait until txfifo is empty

	PUT8(UART0 +0,c);
}
char UART_getC()
{
	while((GET8(UART0+0x14)&0x1)==0);     //wait for a character to be in the rx fifo
	return GET8(UART0+0x0);
}

/*
int UART_putstring(char *str, unsigned int length);
int UART_getstring(char *buf, unsigned int length);
*/


