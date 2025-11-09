/**
 ******************************************************************************
 * @file       main.c
 * @brief      Main APP1 file
 * @name       Jose Francisco Marti Martin
 *******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "Boot.h"
#include "Gpio.h"
#include "Mcu.h"
#include "Irq_handler.h"

/* Typedef -------------------------------------------------------------------*/

/* Define --------------------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Global variables ----------------------------------------------------------*/

/* Private user code ---------------------------------------------------------*/
/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	Mcu_Init();

	Gpio_Init();

	while (1)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);

		if (Irq_GetBootFlag() == TRUE)
		{
			Boot_JumpToBootloader();
		}
	}
}

