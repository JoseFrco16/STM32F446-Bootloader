/**
 ******************************************************************************
 * @file       Ver.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Ver.h"

/* Define --------------------------------------------------------------------*/
#define FW_VERSION_MAJOR   1
#define FW_VERSION_MINOR   0
#define FW_VERSION_PATCH   0

#define FW_VERSION_U32 ((FW_VERSION_MAJOR << 16) | \
                        (FW_VERSION_MINOR << 8)  | \
                        (FW_VERSION_PATCH))

/* Typedef -------------------------------------------------------------------*/

/* Public variables ---------------------------------------------------------*/
static uint32_t Ver_FwVersion = FW_VERSION_U32;

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Public Functions  ---------------------------------------------------------*/
uint32_t Ver_GetVersion( void )
{
	return ( uint32_t )Ver_FwVersion;
}

/* Private Functions  ---------------------------------------------------------*/
