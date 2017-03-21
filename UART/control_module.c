#include "control_module.h"

void CM_setCtrlModule(CONTROL_MODULE_REG_t module, unsigned int value)
{

	PUT32(CONTROL_MODULE_REGISTER_BASE + module, value);
}

unsigned int CM_getCtrlModule(CONTROL_MODULE_REG_t module)
{
	return GET32(CONTROL_MODULE_REGISTER_BASE + module);
}

void Uart0_Mux()
{
		
	CM_setCtrlModule(CM_conf_uart0_rxd, (1 << 4) | (1 << 5));		//Rx muxing
	CM_setCtrlModule(CM_conf_uart0_txd,0);					//tx muxing
	
}


