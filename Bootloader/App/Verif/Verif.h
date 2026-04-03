/**
 ******************************************************************************
 * @file       Verif.h
 * @brief      Target application's verification
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef VERIF__H
#define VERIF__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>
#include <stdio.h>
#include "Types.h"

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/
typedef enum
{
	VALID = 0,
	INVALID,
}Verif_ValidType;

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
/**
 * @brief  Check application target validity.
 *         Magic number and app reset handler check are performed.
 * @retval True Application is valid
 * @retval False Application is not valid
 */
Verif_ValidType Verif_CheckAppValidity( void );

#endif /* VERIF__H */
