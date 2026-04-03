/**
 ******************************************************************************
 * @file       Uart.c
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

/* Private variables ---------------------------------------------------------*/
Uart_LvType Uart_Lv;

/* Private function prototypes -----------------------------------------------*/

/* Public Functions  ---------------------------------------------------------*/
void Uart_Init()
{

	Uart_Lv.huart2.Instance = USART2;
	Uart_Lv.huart2.Init.BaudRate = 115200;
	Uart_Lv.huart2.Init.WordLength = UART_WORDLENGTH_8B;
	Uart_Lv.huart2.Init.StopBits = UART_STOPBITS_1;
	Uart_Lv.huart2.Init.Parity = UART_PARITY_NONE;
	Uart_Lv.huart2.Init.Mode = UART_MODE_TX_RX;
	Uart_Lv.huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	Uart_Lv.huart2.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&Uart_Lv.huart2) != HAL_OK)
    {
        //Error_Handler();
    }

	HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART2_IRQn);

	UART_HandleTypeDef* huart_ptr = &Uart_Lv.huart2;

	/* Enable the UART Error Interrupt: (Frame error, noise error, overrun error) */
	__HAL_UART_ENABLE_IT(huart_ptr, UART_IT_ERR);

	/* Enable the UART Data Register not empty Interrupt */
	__HAL_UART_ENABLE_IT(huart_ptr, UART_IT_RXNE);

	Uart_Lv.rx_irq_status = UART_RX_IDLE;

}

Uart_StatusType Uart_ReadFrame( uint8_t* data_rx, uint8_t length )
{
	Uart_StatusType ret_status = UART_RX_NOK;
	HAL_StatusTypeDef hal_status;

	if( length <= UART_RX_BUFFER )
	{
		memset(Uart_Lv.rx, 0, UART_RX_BUFFER);

		hal_status = HAL_UART_Receive(&Uart_Lv.huart2, Uart_Lv.rx, length, UART_RX_TIMEOUT);

	    if (hal_status == HAL_OK)
	    {
	        ret_status = UART_RX_OK;
	        memcpy(data_rx, Uart_Lv.rx, length);
	    }
	    else
	    {
	    	ret_status = UART_RX_NOK;
	    	data_rx = NULL;
	    }
	}

    return ret_status;
}

Uart_StatusType Uart_WriteFrame( uint8_t* data_tx, uint8_t length )
{
	Uart_StatusType ret_status;
	HAL_StatusTypeDef hal_status;

	if( length > UART_TX_BUFFER )
	{
		ret_status = UART_TX_NOK;
	}
	else
	{
		memset(Uart_Lv.tx, 0, UART_TX_BUFFER);

		hal_status = HAL_UART_Transmit(&Uart_Lv.huart2, data_tx, length, UART_TX_TIMEOUT);

	    if (hal_status == HAL_OK)
	    {
	        ret_status = UART_TX_OK;
	    }
	    else
	    {
	    	ret_status = UART_TX_NOK;
	    }
	}

    return ret_status;
}

Uart_StatusType Uart_ReadFrameIrq( uint8_t* data_rx, uint8_t length )
{
	Uart_StatusType ret_status = UART_RX_NOK;

	if( length <= UART_RX_BUFFER )
	{
		memcpy(data_rx, Uart_Lv.rx, length);
        ret_status = UART_RX_OK;
        Uart_Lv.rx_irq_status = UART_RX_IDLE;
	}

	return ret_status;
}

Uart_StatusType Uart_GetIrqStatusFlag( void )
{
	return Uart_Lv.rx_irq_status;
}

/* Private Functions  ---------------------------------------------------------*/
