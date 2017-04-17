#include "uart.h"
#include "uart_console_header.h"
#include "clock.h"
#include "control_module.h"
#include "string.h"

unsigned short int value = 0;
void GPIO_init()
{
	unsigned int setting = (1<<18) | (0x2<<0);
	CM_SetClk(CM_PER, CM_PER_GPIO1_CLKCTRL, setting);
	while((CM_GetClk(CM_PER, CM_PER_GPIO1_CLKCTRL) & (0x3<<16)) != 0);

}
/* 
 * UART procedure described in 19.4 UART/IrDA/CIR Basic Programming Model
 */

void Uart0_Reset(unsigned int baudrate) 
{
	/** UART reset --> setting SYSC[1] */
	unsigned int temp = GET32(UART0+SYSC);
	temp |= 0x2;
	PUT32(UART0+SYSC, temp);		
	while (((GET32(UART0+SYSS)) & 0x1) == 0);		/* Wait till reset is complete */
	temp = GET8(UART0+SYSC);
	temp |= (0x1 << 0x3);
	PUT8(UART0+SYSC, temp);					/* No idle/Wakeup capability is enabled */

	/* UART init*/
	/* Check below condition is necessary ??*/
	while(!(GET32(UART0+LSR) & 0x40));    		// Transmitter hold (TX	FIFO) and shift	registers are empty

	/* UART Interrupt Enable Register */
	PUT8(UART0+IER, 0);					//Disable uart interrupts
	PUT8(UART0+MDR1,0x7);        				/* Disable modeselect (default) 19.5.1.19*/
	PUT8(UART0+LCR,~(0x7C));    // divisor latch enable, access DLL DHL, set uart as 8bit

	value = GET8(UART0+LCR);
	PUT8(UART0+RHR,0);          // DLL = 0
	PUT8(UART0+IER,0);          // DHL = 0
	PUT8(UART0+LCR,0x3);        // set uart as 8bit
	PUT8(UART0+MCR,0x3);        // force /rts & /drt to active (low) (?!)
	PUT8(UART0+FCR,0x7);        // clear rx&tx FIFOs, and enables them (each 64 bytes deep)

	/**
	  1 . UART 16x mode: Divisor value = Operating frequency/(16x baud rate) , Operating frequency = 48 MHz	 
	  2 . For 115200/16x speed DLL = 0x00, DLH = 0x1A
	  3 . The divisor latches high register(DLH) with the DLL register stores the 14-bit divisor for generation
	      of the baud clock in the baud rate generator
	  */
	float div = 48000000.0/(16.0*(float)baudrate);
	unsigned int intdiv = (unsigned int) div; 
	PUT8(UART0+LCR,~(0x7C));    		   /* divisor latch enable, access DLL DHL, set uart as 8bit*/
	PUT8(UART0+RHR,intdiv&0xFF);          	   /* DLL = 26 */
	PUT8(UART0+IER,(intdiv>>8)&0x3F);          /* DHL = 0  IER now DLH*/

	PUT8(UART0+LCR,0x3);        // set uart as 8 bit
	PUT8(UART0+MDR1,0);          // uart 16x oversampling

}

void UART_init(unsigned int baudrate, STOP_BIT_t stopBit, PARITY_BIT_t parity, FLOW_t flowControl) 
{

	//	GPIO_init();

	//UART mux config
	Uart0_Mux();

	//Init clock and muxing of pins
	Init_UART0_Clk();

	//Uart soft reset
	Uart0_Reset(baudrate);
}

void UART_putC( char c)
{

	if (c == '\n')
		UART_putC('\r');

	while((GET8(UART0+LSR)&0x20) != 0x20)	/* wait until txfifo is empty (check exact bit is set) */ 
		;

	PUT8(UART0 +RHR,c);
}
char UART_getC()
{
	while((GET8(UART0+LSR)&0x1) == 0);     //wait for a character to be in the rx fifo
	return GET8(UART0+RHR);
}

int UART_putString(char *str)
{
   int length = strlen(str);
   for(int i = 0; i < length; i++)
   {
      UART_putC(str[i]);
   }
   return length;
}

int UART_getString(char *buf)
{
   int length = strlen(buf);
   for(int i = 0; i < length; i ++)
   {
      buf[i] = UART_getC();
   }
   return length;
}



