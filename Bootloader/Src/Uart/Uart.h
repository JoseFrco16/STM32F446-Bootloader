/**
 ******************************************************************************
 * @file       Uart.h
 * @brief      Uart configurations
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef UART__H
#define UART__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/
typedef enum {
	UART_RX_OK,
	UART_RX_NOK,
	UART_TX_OK,
	UART_TX_NOK,
} Uart_StatusType;

/* Public function prototypes ------------------------------------------------*/
/**
 * @brief Uart initialization required for bootloader
 */
void Uart_Init();

/**
 * @brief Read Uart Frame using polling
 * @param[out] data_rx Data received
 * @return ret_status Reception status
 */
Uart_StatusType Uart_ReadFrame( uint8_t* data_rx );

/**
 * @brief Write Uart Frame
 * @param[out] data_tx Data to write
 * @return ret_status Transmission status
 */
Uart_StatusType Uart_WriteFrame( uint8_t* data_tx, uint8_t length );

#endif /* UART__H */
