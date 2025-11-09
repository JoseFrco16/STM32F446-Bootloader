/**
 ******************************************************************************
 * @file       main.c
 * @brief      Main bootloader file
 * @name       Jose Francisco Marti Martin
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "stm32f4xx_hal.h"
#include "Boot.h"
#include "Gpio.h"
#include "Mcu.h"
#include "Irq_handler.h"

/* Typedef -------------------------------------------------------------------*/

/* Define --------------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Function prototypes  ------------------------------------------------------*/

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	Mcu_Init();

	Gpio_Init();

	Boot_LedSequence();
	Boot_ManageBootloaderJumps();

	while (1)
	{

	}
}
