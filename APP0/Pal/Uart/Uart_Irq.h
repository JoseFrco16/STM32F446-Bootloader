/**
 ******************************************************************************
 * @file       Uart_Irq.c
 * @brief      Uart's handler
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef UART_IRQ__H
#define UART_IRQ__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>
#include "stm32f4xx_hal.h"

/* Define --------------------------------------------------------------------*/
#define UART_RX_TIMEOUT 1000u
#define UART_TX_TIMEOUT 100u

/* Typedef -------------------------------------------------------------------*/
typedef struct{
	UART_HandleTypeDef huart2;
	uint8_t rx[ UART_RX_BUFFER ];
	uint8_t tx[ UART_TX_BUFFER ];
	Uart_StatusType rx_irq_status;
} Uart_LvType;

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
void USART2_IRQHandler( void );

#endif /* UART_IRQ__H */
