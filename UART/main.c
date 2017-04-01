#include "uart.h"
#include "uart_console_header.h"
#include "clock.h"
#include "types.h"
#include "gpio.h"

void _main(void)
{
	LED_init();

	UART_init(115200,STOP1,PARITY_NONE,FLOW_OFF);
	UART_putC('\n');
	UART_putString("Uart init done : ");
	UART_putString("Hi shashi\n");
	UART_putString("Uart init done : ");
	UART_putString("Hi dabba\n\n");

	while (1) {
		UART_putString("Enter a character : ");
		UART_putC(UART_getC());
		UART_putC('\n');
	}
}
