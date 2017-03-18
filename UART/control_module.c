#include "control_module.h"

void CM_setCtrlModule(CM_REG_t module, unsigned int value)
{

	PUT32(CM_MODULE_REGISTER_BASE + module, value);
}

unsigned int CM_getCtrlModule(CM_REG_t module)
{
	return GET32(CM_MODULE_REGISTER_BASE+module);
}

void Uart0_Mux()
{
		
	CM_setCtrlModule(CM_conf_uart0_rxd, (1 << 4) | (1 << 5));		//Rx muxing
	CM_setCtrlModule(CM_conf_uart0_txd,0);					//tx muxing
	
}


