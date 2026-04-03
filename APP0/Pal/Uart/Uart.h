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
#include "Types.h"

/* Define --------------------------------------------------------------------*/
/* Typical values are 64, 128 or 256 bytes due to Flash write */
#define UART_RX_BUFFER  128u
#define UART_TX_BUFFER  64u

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
/**
 * @brief Uart initialization required for bootloader
 */
void Uart_Init();

/**
 * @brief Read Uart Frame using polling
 * @param[out] data_rx Data received
 * @param[in]  length Number of bytes to be received
 * @return ret_status Reception status
 */
Uart_StatusType Uart_ReadFrame( uint8_t* data_rx, uint8_t length );

/**
 * @brief Write Uart Frame
 * @param[out] data_tx Data to write
 * @param[in]  length Number of bytes to be transmitted
 * @return ret_status Transmission status
 */
Uart_StatusType Uart_WriteFrame( uint8_t* data_tx, uint8_t length );

/**
 * @brief Read Uart Frame without polling (Data received through IRQ)
 * @param[out] data_rx Data received
 * @param[in]  length Number of bytes to be received
 * @return ret_status Reception status
 */
Uart_StatusType Uart_ReadFrameIrq( uint8_t* data_rx, uint8_t length );

/**
 * @brief Get Rx Irq Status Flag
 * @return rx_irq_status IRQ RX status flag
 */
Uart_StatusType Uart_GetIrqStatusFlag( void );

#endif /* UART__H */
