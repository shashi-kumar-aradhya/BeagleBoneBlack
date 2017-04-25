#include <stdio.h>
#include "clock.h"


#define BIT(n) (1 << n)
#define GETBITS(x, p, n) (((unsigned int)x >> (p-n+1)) & ~(~0 << n))
#define SETBITS(x, p, n, y) ((x & ~((~0 << n) << (p-n+1))) | (( y & ~(~0 << n))<< (p-n+1)))



/**************************************************************************
 **				MACRO'S
 *************************************************************************/
#define I2C_INSTANCE	(3)	//I2C0, I2C1, I2C2

/**************************************************************************
 **			I2C registers	
 *************************************************************************/
#define I2C_REVNB_LO		0x00
#define	I2C_REVNB_HI		0x04
#define	I2C_SYSC		0x10
#define	I2C_IRQSTATUS_RAW	0x24
#define	I2C_IRQSTATUS		0x28
#define	I2C_IRQENABLE_SET	0x2c
#define	I2C_IRQENABLE_CLR	0x30
#define	I2C_WE			0x34
#define	I2C_DMARXENABLE_SET	0x38
#define I2C_DMATXENABLE_SET	0x3c
#define I2C_DMARXENABLE_CLR	0x40
#define I2C_DMATXENABLE_CLR	0x44
#define I2C_DMARXWAKE_EN	0x48
#define I2C_DMATXWAKE_EN	0x4c
#define I2C_SYSS		0x90
#define I2C_BUF			0x94
#define I2C_CNT			0x98
#define	I2C_DATA		0x9c
#define I2C_CON			0xa4
#define I2C_OA			0xa8
#define I2C_SA			0xac
#define I2C_PSC			0xb0
#define I2C_SCLL		0xb4
#define I2C_SCLH		0xb8
#define I2C_SYSTEST		0xbc
#define I2C_BUFSTAT		0xc0
#define I2C_OA1			0xc4
#define I2C_OA2			0xc8
#define I2C_OA3			0xcc
#define I2C_ACTOA		0xd0
#define I2C_SBLOCK		0xd4


/***************************************************************************
 **				Field definition macros
 ****************************************************************************/
//SYSC
#define I2C_SYSC_AUTOIDLE	(0x1 << 0)
#define I2C_SYSC_SRST		(0x1 << 1)
#define I2C_SYSC_ENAWAKEUP	(0x1 << 2)
#define I2C_SYSC_IDLEMODE	(0x3 << 3)
#define I2C_SYSC_CLKACTIVITY	(0x3 << 8)

//I2C_IRQSTATUS_RAW
#define I2C_IRQSTATUS_RAW_AL	(0x1 << 0)
#define I2C_IRQSTATUS_RAW_NACK	(0x1 << 1)
#define I2C_IRQSTATUS_RAW_ARDY 	(0x1 << 2)
#define I2C_IRQSTATUS_RAW_RRDY 	(0x1 << 3)
#define I2C_IRQSTATUS_RAW_XRDY 	(0x1 << 4)
#define I2C_IRQSTATUS_RAW_GC	(0x1 << 5)
#define I2C_IRQSTATUS_RAW_STC	(0x1 << 6)
#define I2C_IRQSTATUS_RAW_AERR	(0x1 << 7)
#define I2C_IRQSTATUS_RAW_BF	(0x1 << 8)
#define I2C_IRQSTATUS_RAW_AAS	(0x1 << 9)
#define I2C_IRQSTATUS_RAW_XUDF	(0x1 << 10)
#define I2C_IRQSTATUS_RAW_ROVR	(0X1 << 11)
#define I2C_IRQSTATUS_RAW_BB	(0x1 << 12)
#define I2C_IRQSTATUS_RAW_RDR	(0x1 << 13)
#define I2C_IRQSTATUS_RAW_XDR	(0x1 << 14)

//I2C_IRQSTATUS
#define I2C_IRQSTATUS_AL	(0x1 << 0)
#define I2C_IRQSTATUS_NACK	(0x1 << 1)
#define I2C_IRQSTATUS_ARDY	(0x1 << 2)
#define I2C_IRQSTATUS_RRDY	(0x1 << 3)
#define I2C_IRQSTATUS_XRDY	(0x1 << 4)
#define I2C_IRQSTATUS_GC	(0x1 << 5)
#define I2C_IRQSTATUS_STC	(0x1 << 6)
#define I2C_IRQSTATUS_AERR	(0x1 << 7)
#define I2C_IRQSTATUS_BF	(0x1 << 8)
#define I2C_IRQSTATUS_AAS	(0x1 << 9)
#define I2C_IRQSTATUS_XUDF	(0x1 << 10)
#define I2C_IRQSTATUS_ROVR	(0x1 << 11)
#define I2C_IRQSTATUS_BB	(0x1 << 12)
#define I2C_IRQSTATUS_RDR	(0x1 << 13)
#define I2C_IRQSTATUS_XDR	(0x1 << 14)

//I2C_IRQSTATUS
#define I2C_IRQSTATUS_AL	(0x1 << 0)
#define I2C_IRQSTATUS_NACK	(0x1 << 1)
#define I2C_IRQSTATUS_ARDY	(0x1 << 2)
#define I2C_IRQSTATUS_RRDY	(0x1 << 3)
#define I2C_IRQSTATUS_XRDY	(0x1 << 4)
#define I2C_IRQSTATUS_GC	(0x1 << 5)
#define I2C_IRQSTATUS_STC	(0x1 << 6)
#define I2C_IRQSTATUS_AERR	(0x1 << 7)
#define I2C_IRQSTATUS_BF	(0x1 << 8)
#define I2C_IRQSTATUS_AAS	(0x1 << 9)
#define I2C_IRQSTATUS_XUDF	(0x1 << 10)
#define I2C_IRQSTATUS_ROVR	(0x1 << 11
#define I2C_IRQSTATUS_BB	(0x1 << 12)
#define I2C_IRQSTATUS_RDR	(0x1 << 13)
#define I2C_IRQSTATUS_XDR	(0x1 << 14)

		//I2C_IRQENABLE_SET
#define I2C_IRQENABLE_SET_AL_IE		(0x1 << 0)
#define I2C_IRQENABLE_SET_NACK_IE	(0x1 << 1)
#define I2C_IRQENABLE_SET_ARDY_IE	(0x1 << 2)
#define I2C_IRQENABLE_SET_RRDY_IE	(0x1 << 3)
#define I2C_IRQENABLE_SET_XRDY_IE	(0x1 << 4)
#define I2C_IRQENABLE_SET_GC_IE		(0x1 << 5)
#define I2C_IRQENABLE_SET_STC_IE	(0x1 << 6)
#define I2C_IRQENABLE_SET_AERR_IE	(0x1 << 7)
#define I2C_IRQENABLE_SET_BF_IE		(0x1 << 8)
#define I2C_IRQENABLE_SET_AAS_IE	(0x1 << 9)
#define I2C_IRQENABLE_SET_XUDF		(0x1 << 10)
#define I2C_IRQENABLE_SET_ROVR		(0x1 << 11)
#define I2C_IRQENABLE_SET_RDR_IE	(0x1 << 13)
#define I2C_IRQENABLE_SET_XDR_IE	(0x1 << 14)

//I2C_IRQENABLE_CLR
#define I2C_IRQENABLE_CLR_AL_IE		(0x1 << 0)
#define I2C_IRQENABLE_CLR_NACK_IE	(0x1 << 1)
#define I2C_IRQENABLE_CLR_ARDY_IE	(0x1 << 2)
#define I2C_IRQENABLE_CLR_RRDY_IE	(0x1 << 3)
#define I2C_IRQENABLE_CLR_XRDY_IE	(0x1 << 4)
#define I2C_IRQENABLE_CLR_GC_IE		(0x1 << 5)
#define I2C_IRQENABLE_CLR_STC_IE	(0x1 << 6)
#define I2C_IRQENABLE_CLR_AERR_IE	(0x1 << 7)
#define I2C_IRQENABLE_CLR_BF_IE		(0x1 << 8)
#define I2C_IRQENABLE_CLR_AAS_IE	(0x1 << 9)
#define I2C_IRQENABLE_CLR_XUDF		(0x1 << 10)
#define I2C_IRQENABLE_CLR_ROVR		(0x1 << 11)
#define I2C_IRQENABLE_CLR_RDR_IE	(0x1 << 13)
#define I2C_IRQENABLE_CLR_XDR_IE	(0x1 << 14)

//I2C_SYSS
#define I2C_SYSS_RDONE			(0x1 << 0)

//I2C_CON
#define I2C_CON_STT			(0x1 << 0)
#define I2C_CON_STP			(0x1 << 1)
#define I2C_CON_XOA3			(0x1 << 4)
#define I2C_CON_XOA2			(0x1 << 5)
#define I2C_CON_XOA1			(0x1 << 6)
#define I2C_CON_XOA0			(0x1 << 7)
#define I2C_CON_XSA			(0x1 << 8)
#define I2C_CON_TRX			(0x1 << 9)
#define I2C_CON_MST			(0x1 << 10)
#define I2C_CON_STB			(0x1 << 11)
#define I2C_CON_OPMODE			(0x3 << 12)
#define I2C_CON_I2C_EN			(0x1 << 15)

//I2C_PSC
#define I2C_PSC				(0Xff << 0)

//I2C_SCLL
#define I2C_SCLL			(0xff << 0)

//I2C_SCLH
#define I2C_SCLH			(0xff << 0)


/** 
1.The I2C_EN bit in the I2C_CON register can be used to hold the I2C module in reset. When the
  system bus reset is removed (PIRSTNA = 1), I2C_EN = 0 keeps the functional part of I2C module in
  reset state and all configuration registers can be accessed. I2C_EN = 0 does not reset the registers to
  power up reset values 
2.A software reset by setting the SRST bit in the I2C_SYSC register. This bit has exactly the same
  action on the module logic as the system bus reset. All registers are reset to power up reset values. 
3.The I2C_EN bit in the I2C_CON register can be used to hold the I2C module in reset. When the
  system bus reset is removed (PIRSTNA = 1), I2C_EN = 0 keeps the functional part of I2C module in
  reset state and all configuration registers can be accessed. I2C_EN = 0 does not reset the registers to
  power up reset values.
*/

static void I2CMasterDisable(uint32_t baseaddr)
{
	PUT32(baseaddr + I2C_CON) &= ~I2C_EN;
}

static void I2CSoftReset(uint32_t baseaddr)
{
	PUT32(baseaddr + I2C_SYSC) |= I2C_SYSC_SRST;

}
static void I2CAutoIdleDisable(uint32_t baseaddr)
{
	PUT32(baseaddr + I2C_SYSC) &= ~I2C_SYSC_AUTOIDLE;
}
static void _i2c_init(I2C_t i2c)
{
	uint32_t inst_addr = get_i2c_addr(i2c);

	/** do soft reset : 21.3.3 I2C Reset */
	I2CMasterDisable(inst_addr);
	I2CSoftReset(inst_addr);

	
}
