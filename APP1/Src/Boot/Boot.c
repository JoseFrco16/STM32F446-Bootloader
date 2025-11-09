/**
 ******************************************************************************
 * @file       Boot.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Boot.h"
#include "stm32f4xx_hal.h"

/* Typedef -------------------------------------------------------------------*/
typedef void (*pAppRestHandler)(void);

/* Define --------------------------------------------------------------------*/
#define BOOT_BOOTLOADER_START_ADDR  0x8000000

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Public Functions  ---------------------------------------------------------*/
void Boot_JumpToBootloader(void)
{
	uint32_t
	appStack = *(__IO uint32_t*)BOOT_BOOTLOADER_START_ADDR;
	uint32_t
	appResetHandler = *(__IO uint32_t*)(BOOT_BOOTLOADER_START_ADDR + 4);

	HAL_RCC_DeInit();
	HAL_DeInit();

	/* Disable SysTick */
	SysTick->CTRL = 0;
	SysTick->LOAD = 0;
	SysTick->VAL = 0;

	/* Set vector table */
	SCB->VTOR = BOOT_BOOTLOADER_START_ADDR;

	/* Set Main Stack Pointer */
	__set_MSP(appStack);

	/* Jump to Bootloader */
	pAppRestHandler JumpToBootloader = (pAppRestHandler) appResetHandler;
	JumpToBootloader();
}

/* Private Functions  ---------------------------------------------------------*/

