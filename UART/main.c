#include "uart.h"
#include "uart_console_header.h"
#include "clock.h"
#include "types.h"
#include "gpio.h"

extern unsigned short int value;
char array[100];
void num_rev(unsigned int value)
{
	int i = 0;
	while (value) {
	array[i] = value % 10;
	value /= 10;
	}
}



void uart_putf(const char *fmt, ...) {
    int *stack_head = __builtin_frame_address(0);
    stack_head += 2; // skip fmt, skip stack_head

    while (*fmt) {
        if (*fmt == '%') {
            fmt++;
            switch (*fmt++) {
                case 'c':
                    UART_putC(*stack_head++);
                    break;
                case 's': {
                    const char *s = (char *) *stack_head++;
                    while (*s) {
                        UART_putC(*s++);
                    }
                    break;
                }
                case 'x': {
                    int num = *stack_head++;
                    int shift = 28;
                    UART_putC('0');
                    UART_putC('x');
                    while (shift >= 0) {
                        int hd = (num >> shift) & 0xf;
                        if (hd > 9)
                            hd += 'A' - 10;
                        else
                            hd += '0';
                        UART_putC(hd);
                        shift -= 4;
                    }
                    break;
                }
                case 'i':
                case 'd': {
                    int num = *stack_head++;
                    char buf[16];
                    char *s = buf + (sizeof(buf) / sizeof(buf[0])) - 1;
                    char *e = s;

                    do {
                        *--s = '0' + num % 10;
                    } while (num /= 10);

                    while (s < e)
                        UART_putC(*s++);

                    break;
                }
                default:
                    UART_putC('?');
            }
        } else {
            UART_putC(*fmt++);
        }
    }
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
	uart_putf("LCR value = %x\n", value);
	while (1) {
		UART_putString("Enter a character : ");
		UART_putC(UART_getC());
		UART_putC('\n');
	}

}
