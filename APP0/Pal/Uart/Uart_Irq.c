/**
 ******************************************************************************
 * @file       Uart_Irq.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Uart.h"
#include "Uart_Irq.h"
#include "string.h"
#include "Types.h"


/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/
extern Uart_LvType Uart_Lv;

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Public Functions  ---------------------------------------------------------*/
void USART2_IRQHandler( void )
{
	uint8_t rx_index = 0;

	memset(Uart_Lv.rx, 0, UART_RX_BUFFER);

    while (USART2->SR & USART_SR_RXNE)
    {
        Uart_Lv.rx[ rx_index ] = USART2->DR;
        rx_index++;
    }

    if (USART2->SR & (USART_SR_ORE | USART_SR_FE | USART_SR_NE))
    {
    	Uart_Lv.rx_irq_status = UART_RX_NOK;
    }
    else
    {
    	Uart_Lv.rx_irq_status = UART_RX_OK;
    }
}

/* Private Functions  ---------------------------------------------------------*/
