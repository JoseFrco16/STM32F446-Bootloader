/**
 ******************************************************************************
 * @file       Boot.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Boot.h"
#include "Uart.h"
#include "stm32f4xx_hal.h"
#include "stdio.h"

/* Define --------------------------------------------------------------------*/
#define BOOT_APP_START_ADDR 0x08008000

/* Enum  ----------------------------------------------------------------------*/
enum Boot_Cmd{
	PING = 0,
	BOOT_VERSION,
	DEVICE_INFO,
	ERASE_FLASH,
	WRITE_FLASH,
	COMPUTE_CRC,
	AUTHENTICATE,
	UNLOCK,
	JUMP_TO_APPLICATION,
	MCU_RESET,
};

/* Typedef -------------------------------------------------------------------*/
typedef void (*pAppRestHandler)(void);


/* Private variables ---------------------------------------------------------*/
/* Private RAM Variable stored in .noinit section */
__attribute__((section(".noinit")))  uint8_t Boot_AppFlag;

/* Private function prototypes -----------------------------------------------*/
/**
 * @brief Jump to Application stored in BOOT_APP_START_ADDR
 */
void Boot_JumpToApp(void);

/* Public Functions  ---------------------------------------------------------*/
void Boot_ManageBootloader( void )
{
	if( Boot_AppFlag == True )
	{

	}
}


void Boot_ExecuteBootloaderCmdAction( int8_t cmd )
{
	switch( cmd )
	{
	case PING:
		printf("Ping");
		break;

	case BOOT_VERSION:

		printf("Boot Version");
		break;

	case DEVICE_INFO:

		break;

	case ERASE_FLASH:

		break;

	case WRITE_FLASH:

		break;

	case COMPUTE_CRC:

		break;

	case AUTHENTICATE:

		break;

	case UNLOCK:

		break;

	case JUMP_TO_APPLICATION:

		break;

	case MCU_RESET:

		break;

	default:
		break;
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
void Boot_JumpToApp(void)
{
	uint32_t appStack = *(__IO uint32_t*) BOOT_APP_START_ADDR;
	uint32_t appResetHandler = *(__IO uint32_t*) (BOOT_APP_START_ADDR + 4);

	HAL_RCC_DeInit();
	HAL_DeInit();

	/* Disable SysTick */
	SysTick->CTRL = 0;
	SysTick->LOAD = 0;
	SysTick->VAL = 0;

	/* Set vector table */
	SCB->VTOR = BOOT_APP_START_ADDR;

	/* Set Main Stack Pointer */
	__set_MSP(appStack);

	/* Jump to Reset Handler of App0 */
	pAppRestHandler JumpToApplication = (pAppRestHandler) appResetHandler;
	JumpToApplication();
}

