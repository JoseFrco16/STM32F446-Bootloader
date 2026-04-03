/**
 ******************************************************************************
 * @file       Verif.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Verif.h"
#include "Header.h"

/* Define --------------------------------------------------------------------*/
#define VERIF_INVALID_FLASH_MASK 0xFF000000u
#define VERIF_VALID_FLASH_ORIGIN 0x08000000u

/* Enum  ----------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Public Functions  ---------------------------------------------------------*/
Verif_ValidType Verif_CheckAppValidity( void )
{
	Bool_Type app_validity = True;
	uint32_t reset_handler = *( uint32_t* )HEADER_APP_START_ADDR;

	if( HEADER_MAGIC_NUMBER != Header_GetMagicNumber() )
	{
		app_validity = False;
	}
	else if( ( reset_handler & VERIF_INVALID_FLASH_MASK ) != VERIF_VALID_FLASH_ORIGIN )
	{
		app_validity = False;
	}

	return app_validity;
}

/* Private Functions  ---------------------------------------------------------*/

