/**
 ******************************************************************************
 * @file       App_main.c
 * @brief      Main bootloader file
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Boot.h"
#include "Pal_Mngr.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/
typedef void (*pAppRestHandler)(void);
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Function definitions ------------------------------------------------------*/

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	printf("Hello World\n");
	Pal_Init();
	printf("Hello World2\n");
	Boot_ManageBootloader();
	printf("Init\n");

	/* ----------------------- */

	/* Checks */
	uint8_t msg[] = "Bootloader finish\r\n";

	//while (1)
	//{
	Uart_WriteFrame(msg, 20);
	HAL_Delay(1000);
	//}

	// For testing
	uint32_t appStack = *(volatile uint32_t*) 0x08008400u;
	uint32_t appResetHandler = *(volatile uint32_t*) (0x08008400u + 4);

	HAL_RCC_DeInit();
	HAL_DeInit();

	/* Disable SysTick */
	SysTick->CTRL = 0;
	SysTick->LOAD = 0;
	SysTick->VAL = 0;

	/* Set vector table */
	SCB->VTOR = 0x08008400u;

	/* Set Main Stack Pointer */
	__set_MSP(appStack);

	/* Jump to Reset Handler of App0 */
	pAppRestHandler JumpToApplication = (pAppRestHandler) appResetHandler;
	JumpToApplication();
}
