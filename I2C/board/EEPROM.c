//#include <stdint.h>
#include "type.h"
#include "I2C.h" 
#include "EEPROM.h" 


#define Address_24xx32A 	(0xa0)

uint32_t EEPROM_read(uint32_t startAddress, uint8_t *b, uint32_t length)
{
	uint8_t rxb[5];
	rxb[0] = (uint8_t) startAddress >> 4;
	rxb[1] = (uint8_t) startAddress & 0xff;

	if (I2C_write(I2C0, 0xa0, &rxb[0], 2)) {
		return I2C_read(I2C0, 0xa0, b, length);
	}
	return 0;
}	
