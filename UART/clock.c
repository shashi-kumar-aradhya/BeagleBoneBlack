#include "clock.h"

void CM_SetClk(CLK_MODULE_t module, CM_MODULE_REG reg, unsigned int value)
{

	PUT32(module+reg, value);
}

unsigned int CM_GetClk(CLK_MODULE_t module, CM_MODULE_REG reg)
{
	return GET32(module+reg);
}

void Init_UART0_clk()
{
	CM_SetClk(CM_PER, CM_PER_GPIO1_CLKCTRL, ((1 << 18) | 0x2));			//Setting GPIO1 CLK to 0x40002
//	while ((CM_GetClk(CM_PER, CM_PER_GPIO1_CLKCTRL) & (0x3 << 16)) != 0 ) ;		//Wait till clock becomes fully functional
	

	CM_SetClk(CM_PER, CM_PER_L4HS_CLKCTRL, ((1 << 18) | 0x2));			//Setting GPIO1 CLK to 0x40002
   

}


