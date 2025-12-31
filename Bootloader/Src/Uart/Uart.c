/**
 ******************************************************************************
 * @file       Uart.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Uart.h"
#include <string.h>
#include "stm32f4xx_hal.h"

/* Define --------------------------------------------------------------------*/
/* Typical values are 64, 128 or 256 bytes due to Flash write */
#define UART_RX_BUFFER  128u
#define UART_TX_BUFFER  64u
#define UART_RX_TIMEOUT 5u
#define UART_TX_TIMEOUT 5u

/* Typedef -------------------------------------------------------------------*/
typedef struct{
	UART_HandleTypeDef huart2;
	uint8_t rx[ UART_RX_BUFFER ];
	uint8_t tx[ UART_TX_BUFFER ];
} Uart_LvType;

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
}

Uart_StatusType Uart_ReadFrame( uint8_t* data_rx )
{
	Uart_StatusType ret_status;
	HAL_StatusTypeDef hal_status;

	hal_status = HAL_UART_Receive(&Uart_Lv.huart2, Uart_Lv.rx, UART_RX_BUFFER, UART_RX_TIMEOUT);

    if (hal_status == HAL_OK)
    {
        ret_status = UART_RX_OK;
        data_rx = Uart_Lv.rx;
    }
    else
    {
    	ret_status = UART_RX_NOK;
    	*data_rx = 0u;
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
		memcpy(Uart_Lv.tx, data_tx, length);
		hal_status = HAL_UART_Transmit(&Uart_Lv.huart2, Uart_Lv.tx, length, UART_TX_TIMEOUT);

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

/* Private Functions  ---------------------------------------------------------*/
