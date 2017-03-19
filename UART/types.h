#ifndef __HEADER_H_
#define __HEADER_H_

typedef unsigned int		uint32_t;
typedef unsigned short int	uint16_t;
typedef unsigned char		uint8_t;

typedef int			int32_t;
typedef short int		int16_t;
typedef char			int8_t;


#define PUT32(addr, val) (*(volatile uint32_t *) (addr) = (unsigned int) (val))
#define GET32(addr) (*(volatile uint32_t *) (addr))

/*
#define PUT16(addr, val) (*(volatile uint16_t *) (addr) = (uint16_t) (val))
#define GET16(addr) (*(volatile uint16_t *) (addr))

#define PUT32(addr, val) (*(volatile uint8_t *) (addr) = (uint8_t)) (val))
#define GET32(addr) (*(volatile uint8_t *) (addr))
*/
#endif
