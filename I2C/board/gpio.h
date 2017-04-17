#ifndef __GPIO_H_
#define __GPIO_H_
#define GPIO1_BASE		 0X4804C000
#define GPIO_OE  		 0X134
#define GPIO_SETDATAOUT 	 0X194

#define CM_PER_BASE 		 0x44e00000
#define CM_PER_GPIO1		 0xac

void LED_init(void);
#endif
