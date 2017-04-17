#ifndef __24XX32A_H
#define __24XX32A_H

#include <stdio.h>


struct EEPROM_ID 
{
#pragma pack(1)
	/**
	 * Brief Magic number, should be equal to 0xEE3355AA
	 * Name = A335X_SK"
	 * Version = 1.0A
	 * SerialNumber = WWYY4P19nnnn
	 * ConfigOpt = SKU#00 is default configuration and remaining 26 bytes are reserved
   	 **/	


	uint32_t magic;
	uint8_t boardName[8];
	uint8_t version[4];
	uint8_t serialNumber[12];
	uint8_t	configOption[32];
};


uint32_t EEPROM_read(uint32_t startAddress, uint8_t *b, uint32_t length);

#endif
