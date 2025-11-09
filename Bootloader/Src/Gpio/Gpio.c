/**
 ******************************************************************************
 * @file       Gpio.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Gpio.h"
#include "stm32f4xx_hal.h"

/* Typedef -------------------------------------------------------------------*/

/* Define --------------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Public Functions  ---------------------------------------------------------*/
void Gpio_Init()
{
	/* Enable CLK in Port A*/
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_InitStruct =
	{ 0 };
	GPIO_InitStruct.Pin = GPIO_PIN_5;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* Private Functions  ---------------------------------------------------------*/
