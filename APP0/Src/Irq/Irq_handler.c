/**
 ******************************************************************************
 * @file       Irq_handler.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Irq_handler.h"
#include "stm32f4xx_hal.h"

/* Typedef -------------------------------------------------------------------*/

/* Define --------------------------------------------------------------------*/

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

void Error_Handler(void)
{
	__disable_irq();

	while (1)
	{
	}

}

void SysTick_Handler(void)
{
	HAL_IncTick();
}

void EXTI15_10_IRQHandler(void)
{
	/* reset chip */
	Irq_BootFlag = TRUE;
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_13);
}

/* Private Functions  ---------------------------------------------------------*/
