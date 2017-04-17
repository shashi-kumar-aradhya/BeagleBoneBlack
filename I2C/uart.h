#ifndef __UART_H_
#define __UART_H_

#include "types.h"

#define UART0		0X44E09000
/*
#define UART1		0X48022000
#define UART2		0X48024000
#define UART3		0X481A6000
#define UART4		0X481A8000
#define UART5		0X481A9000
 */



typedef enum
{
	//UART_REGISTERS

	RHR       	= 0x0,
	THR     	= 0x0,
	IER 		= 0x4,
	IIR 		= 0x8,
	FCR		= 0x8,
	LCR 		= 0xC, 
	MCR 		= 0x10,
	LSR 		= 0x14,
	MSR 		= 0x18,
	TCR 		= 0x18,
	SPR 		= 0x1c,
	TLR 		= 0x1c,
	MDR1 		= 0x20,
	MDR2 		= 0x24,
	SFLSR 		= 0x28,
	TXFLL		= 0x28,
	RESUME 	 	= 0x2c,
	TXFLH		= 0x2c,
	SFREGL 		= 0x30,
	RXFLL		= 0x30,
	SFREGH 		= 0x34,
	RXFLH		= 0x34,
	BLR 		= 0x38,
	ACREG 		= 0x3c,
	SCR 		= 0x40,
	SSR 		= 0x44,
	EBLR 		= 0x48,
	MVR 		= 0x50,
	SYSC 		= 0x54,
	SYSS 		= 0x58,
	WER 		= 0x5c,
	CFPS 		= 0x60,
	RXFIFO_LVL 	= 0x64,
	TXFIFO_LVL 	= 0x68,
	IER2 		= 0x6c,
	ISR2 		= 0x70,
	FREQ_SEL 	= 0x74,
	//78h - - - - - -
	//7Ch - - - - - -
	MDR3 		= 0x80,
	TXDMA 		= 0x84

}UART_REGISTERS_t;
#endif
