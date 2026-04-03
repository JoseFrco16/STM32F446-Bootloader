/**
 ******************************************************************************
 * @file       Mcu.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Mcu.h"
#include "stm32f4xx_hal.h"

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/
typedef void (*pAppRestHandler)(void);

/* Public variables ----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void);

/* Public Functions  ---------------------------------------------------------*/
void Mcu_Init()
{
	HAL_Init();
	SystemClock_Config();
}

void Mcu_JumpToApp( uint32_t AppAddress )
{

	uint32_t appStack = *(volatile uint32_t*) AppAddress;
	uint32_t appResetHandler = *(volatile uint32_t*) (AppAddress + 4);

	HAL_RCC_DeInit();
	HAL_DeInit();

	/* Disable SysTick */
	SysTick->CTRL = 0;
	SysTick->LOAD = 0;
	SysTick->VAL = 0;

	/* Set vector table */
	SCB->VTOR = AppAddress;

	/* Set Main Stack Pointer */
	__set_MSP(appStack);

	/* Jump to Reset Handler of App0 */
	pAppRestHandler JumpToApplication = (pAppRestHandler) appResetHandler;
	JumpToApplication();
}

void Mcu_Reset()
{
	NVIC_SystemReset();
}

/* Private Functions  ---------------------------------------------------------*/
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct =
	{ 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct =
	{ 0 };

	__HAL_RCC_SYSCFG_CLK_ENABLE();

	/** Configure the main internal regulator output voltage
	 */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
	{
		Error_Handler();
	}
}
