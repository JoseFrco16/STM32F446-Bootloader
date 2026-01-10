/**
 ******************************************************************************
 * @file       Boot.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Boot.h"
#include "Boot_Handlers.h"
#include "Gpio.h"

/* Define --------------------------------------------------------------------*/

/* Enum  ----------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/* Private RAM Variable stored in not initialized section */
NO_INIT_SECTION uint8_t Boot_AppFlag;

/* Private function prototypes -----------------------------------------------*/
/**
 * @brief Bootloader user led sequence
 */
static void Boot_LedSequence( void );

/* Public Functions  ---------------------------------------------------------*/
void Boot_ManageBootloader( void )
{
	Boot_LedSequence();

	if( Boot_AppFlag == True )
	{
		Boot_ExecuteCmd( 0 );
	}
}

/* Private Functions  ---------------------------------------------------------*/
static void Boot_LedSequence( void )
{
	for (int time = 100; time > 0; time -= 10)
	{
		Gpio_SetPin( USER_LED, HIGH );
		HAL_Delay(time);
		Gpio_SetPin( USER_LED, LOW );
		HAL_Delay(time);
	}
}

