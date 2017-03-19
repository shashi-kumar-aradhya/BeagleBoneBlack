#include "clock.h"

void CM_SetClk(CLK_MODULE_t module, CM_PER_REG reg, unsigned int value)
{

	PUT32(module+reg, value);
}

unsigned int CM_GetClk(CLK_MODULE_t module, CM_PER_REG reg)
{
	return GET32(module+reg);
}

void Init_UART0_clk()
{

	unsigned int temp;
	 // software-forced wake-up transition on the "always on clock domain", TRM Table 8-92
	temp = CM_GetClk(CM_WKUP,CM_WKUP_CLKSTCTRL);		//This register enables the domain power state transition. It controls the SW supervised clock domain state transition between ON-ACTIVE and ON-INACTIVE states. It also hold one status bit per clock input of the domain
	temp &= ~(0x3);
	temp |= (0x3);
	CM_SetClk(CM_PER, CM_PER_CLKSTCTRL, temp);		//0x2=SW_WKUP


	temp = CM_GetClk(CM_PER, CM_PER,L4HS_CLKSTCTRL);	//This register enables the domain power state transition. It controls the SW supervised clock domain state transition between ON-ACTIVE and ON-INACTIVE states. It also hold one status bit per clock input of the domain
	temp &= ~(0x3);
	temp |= (0x3);
	CM_SetClk(CM_PER, CM_PER_L4HS_CLKSTCTRL, temp);		//0x2=SW_WKUP
   

}


