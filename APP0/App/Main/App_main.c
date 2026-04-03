/**
 ******************************************************************************
 * @file       App_main.c
 * @brief      Main application file
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Pal_Mngr.h"

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/**
 * @brief Led sequence of application
 */
void App_LedSequence( void );

/* Private function prototypes -----------------------------------------------*/

/* Function definitions ------------------------------------------------------*/

/**
 * @brief  Application's entry point.
 * @retval int
 */
int main(void)
{
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	Pal_Init();

	while (1)
	{
		App_LedSequence();

		if( Uart_GetIrqStatusFlag == UART_RX_OK )
		{
			Boot_CheckBootRequest();
		}
	}

	return 0;
}

void App_LedSequence( void )
{
	Gpio_SetPin( USER_LED, HIGH );
	Timer_Delay(1000);
	Gpio_SetPin( USER_LED, LOW );
	Timer_Delay(1000);
}
