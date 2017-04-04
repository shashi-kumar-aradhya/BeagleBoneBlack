#ifndef __UART_CONSOLE_H_
#define __UART_CONSOLE_H_

#include "types.h"

/**
 * Brief flow control
 */
typedef enum
{
	FLOW_OFF = 0,
	FLOW_ON = 1
}FLOW_t;

/**
 * @brief Parity control
 **/
typedef enum
{
	PARITY_NONE,
	PARITY_EVEN,
	PARITY_ODD
}PARITY_BIT_t;




/**
 * stop control
 */
typedef enum
{
	STOP1,
	STOP1_5,
	STOP2
}STOP_BIT_t;

void UART_init(unsigned int baudrate, STOP_BIT_t stopBit, PARITY_BIT_t parity, FLOW_t flowControl);

/**
 * @brief		Send a character
 * @param[in] uart	Character to send
 * @return		void
 */
void UART_putC(char c);

/**
 * @brief		Get a character
 * @return		The character gotten from the uart
 */
char UART_getC();

/**
 * @fn int UART_putString(UART_t uart, char *str, unsigned int length)
 * @brief                  Send a string.
 * @param[in] str          Pointer to the string to send.
 * @param[in] length       Length of the string to send.
 * @return                 The length sent.
 */
int UART_putString(char *str);

/**
 * @fn int UART_getString(UART_t uart, char *buf, unsigned int length)
 * @brief                  Get a string.
 * @param[out] str         Pointer to the location where to put the string read.
 * @param[in]  length      Length to read.
 * @return                 The lenght read
 */
int UART_getString(char *buf);

void Uart0_Reset(unsigned int baudrate); 
#endif


