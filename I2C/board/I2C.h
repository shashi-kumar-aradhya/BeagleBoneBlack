#ifndef __I2C_H
#define __I2C_H

#include "I2C.h"

typedef enum
{
	I2C0 = 0,
	I2C1 = 1,
	I2C2 = 2
}I2C_t;


uint32_t I2C_write(I2C_t i2c, uint8_t slave_addr, uint8_t* b, uint32_t length);
uint32_t I2C_read(I2C_t i2c, uint8_t slave_addr, uint8_t* b, uint32_t length);

#endif
