#include "uart.h"
#include "uart_console_header.h"
#include "clock.h"
#include "types.h"
#include "gpio.h"
#include "sys_log.h"

extern unsigned short int value;

void uart_putf(const char *fmt, ...) 
{
	out_func_t fn = UART_putC;
	va_list ap;
	va_start(ap, fmt);    
	_vprintk(fn, fmt, ap);                               
	va_end(ap); 
}

void _main(void)
{
	LED_init();
	UART_init(115200,STOP1,PARITY_NONE,FLOW_OFF);
	UART_putC('\n');
	UART_putString("Uart init done : ");
	UART_putString("Hi shashi\n");
	UART_putString("Uart init done : ");
	UART_putString("Hi dabba\n\n");
	UART_putString("Uart init done : ");
	UART_putString("Hi dabba\n\n");
	uart_putf("LCR value = %x\n", value);
	while (1) {
		UART_putString("Enter a character : ");
		UART_putC(UART_getC());
		UART_putC('\n');
	}

}
