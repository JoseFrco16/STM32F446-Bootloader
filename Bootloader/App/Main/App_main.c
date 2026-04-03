/**
 ******************************************************************************
 * @file       App_main.c
 * @brief      Main bootloader file
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Boot.h"
#include "Verif.h"
#include "Pal_Mngr.h"
#include "Header.h"
#include <stdio.h>

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
	printf("Hello World\n");
	Pal_Init();
	printf("Hello World2\n");
	Boot_ManageBootloader();
	printf("Init\n");

	if( Verif_CheckAppValidity() != INVALID )
	{
		Mcu_JumpToApp( HEADER_APP_START_ADDR );
	}
	else
	{
		Mcu_Reset();
	}
}
