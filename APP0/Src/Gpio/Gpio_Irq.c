/**
 ******************************************************************************
 * @file       Gpio_Irq.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include <Gpio_Irq.h>
#include "stm32f4xx_hal.h"

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
uint8_t Irq_BootFlag = FALSE;

/* Private function prototypes -----------------------------------------------*/

/* Public Functions  ---------------------------------------------------------*/
uint8_t Irq_GetBootFlag(void)
{
	uint8_t Irq_BootFlagCpy = Irq_BootFlag;

	Irq_BootFlag = FALSE;

	return Irq_BootFlagCpy;
}

void EXTI15_10_IRQHandler(void)
{
	/* reset chip */
	Irq_BootFlag = TRUE;
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_13);
}

/* Private Functions  ---------------------------------------------------------*/
