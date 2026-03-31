/**
 ******************************************************************************
 * @file       Boot.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Boot.h"
#include "Boot_AppHeaderFlags.h"
#include "Boot_Protocol.h"
#include "Boot_Handlers.h"
#include "Gpio.h"

/* Define --------------------------------------------------------------------*/

/* Enum  ----------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
HEADER_SECTION Boot_HeaderFlagsType Boot_HeaderFlags;

/* Private function prototypes -----------------------------------------------*/
/**
 * @brief Bootloader user led sequence
 */
static void Boot_LedSequence( void );

/* Public Functions  ---------------------------------------------------------*/
void Boot_ManageBootloader( void )
{
	Bool_Type boot_finish = False;
	Boot_RxProtocolType* RxProtocol = NULL;

	/* Initial Boot Led Sequence */
	Boot_LedSequence();

	if( Boot_HeaderFlags.ota_flag == True )
	{
		do
		{
			Boot_LedSequence();
			RxProtocol = Boot_ReadCmd();
			boot_finish = Boot_ExecuteCmd( RxProtocol );

		}
		while( boot_finish == False );

		Boot_HeaderFlags.ota_flag = False;
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

