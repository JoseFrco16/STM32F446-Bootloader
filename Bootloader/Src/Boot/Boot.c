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
#define BOOT_APP0_START_ADDR 0x08008000
#define BOOT_APP1_START_ADDR 0x08010000
#define BOOT_APP0_FLAG       0u
#define BOOT_APP1_FLAG       1u

/* Private variables ---------------------------------------------------------*/
/* Private RAM Variable stored in .noinit section */
__attribute__((section(".noinit")))  uint8_t Boot_AppFlag;

/* Private function prototypes -----------------------------------------------*/
/**
 * @brief Jump to the Application 0 stored in BOOT_APP0_START_ADDR
 */
void Boot_JumpToApp0(void);

/**
 * @brief Jump to the Application 1 stored in BOOT_APP1_START_ADDR
 */
void Boot_JumpToApp1(void);

/* Public Functions  ---------------------------------------------------------*/
void Boot_ManageBootloaderJumps(void)
{
	if (Boot_AppFlag == BOOT_APP0_FLAG)
	{
		Boot_AppFlag = BOOT_APP1_FLAG;
		Boot_JumpToApp0();
	}
	else if (Boot_AppFlag == BOOT_APP1_FLAG)
	{
		Boot_AppFlag = BOOT_APP0_FLAG;
		Boot_JumpToApp1();
	}
	else
	{
		Boot_AppFlag = BOOT_APP1_FLAG;
		Boot_JumpToApp0();
	}
}

void Boot_LedSequence(void)
{
	for (int time = 100; time > 0; time -= 10)
	{
		HAL_GPIO_WritePin( GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
		HAL_Delay(time);
		HAL_GPIO_WritePin( GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
		HAL_Delay(time);
	}
}

/* Private Functions  ---------------------------------------------------------*/
void Boot_JumpToApp0(void)
{
	uint32_t appStack = *(__IO uint32_t*) BOOT_APP0_START_ADDR;
	uint32_t appResetHandler = *(__IO uint32_t*) (BOOT_APP0_START_ADDR + 4);

	HAL_RCC_DeInit();
	HAL_DeInit();

	/* Disable SysTick */
	SysTick->CTRL = 0;
	SysTick->LOAD = 0;
	SysTick->VAL = 0;

	/* Set vector table */
	SCB->VTOR = BOOT_APP0_START_ADDR;

	/* Set Main Stack Pointer */
	__set_MSP(appStack);

	/* Jump to Reset Handler of App0 */
	pAppRestHandler JumpToApplication = (pAppRestHandler) appResetHandler;
	JumpToApplication();
}

void Boot_JumpToApp1(void)
{
	uint32_t appStack = *(__IO uint32_t*) BOOT_APP1_START_ADDR;
	uint32_t appResetHandler = *(__IO uint32_t*) (BOOT_APP1_START_ADDR + 4);

	HAL_RCC_DeInit();
	HAL_DeInit();

	/* Disable SysTick */
	SysTick->CTRL = 0;
	SysTick->LOAD = 0;
	SysTick->VAL = 0;

	/* Set vector table */
	SCB->VTOR = BOOT_APP1_START_ADDR;

	/* Set Main Stack Pointer */
	__set_MSP(appStack);

	/* Jump to Reset Handler of App1 */
	pAppRestHandler JumpToApplication = (pAppRestHandler) appResetHandler;
	JumpToApplication();
}
