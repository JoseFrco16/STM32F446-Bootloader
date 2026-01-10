/**
 ******************************************************************************
 * @file       App_main.c
 * @brief      Main bootloader file
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Boot.h"
#include "Pal_Mngr.h"

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Function definitions ------------------------------------------------------*/

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	Pal_Init();
	Boot_ManageBootloader();

	/* Checks */
	uint8_t msg[] = "Hola\r\n";

	while (1)
	{
		Uart_WriteFrame(msg, 6);
		HAL_Delay(1000);
	}
}
