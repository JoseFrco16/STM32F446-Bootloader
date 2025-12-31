/**
 ******************************************************************************
 * @file       main.c
 * @brief      Main bootloader file
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "stm32f4xx_hal.h"
#include "Boot.h"
#include "Gpio.h"
#include "Mcu.h"
#include "Uart.h"

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Function definitions ------------------------------------------------------*/

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	Mcu_Init();

	Gpio_Init();
	Uart_Init();

	Boot_LedSequence();
	uint8_t msg[] = "Hola\r\n";

	//Boot_ManageBootloaderJumps();

	while (1)
	{
		Uart_WriteFrame(msg, 6);
		HAL_Delay(1000);
	}
}
