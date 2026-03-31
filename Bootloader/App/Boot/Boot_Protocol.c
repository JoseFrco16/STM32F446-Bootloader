/**
 ******************************************************************************
 * @file       Boot_Protocol.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Boot.h"
#include "Boot_Protocol.h"
#include "string.h"

/* Define --------------------------------------------------------------------*/

/* Enum  ----------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
Boot_TxProtocolType Boot_TxProtocol;
Boot_RxProtocolType Boot_RxProtocol;

/* Private function prototypes -----------------------------------------------*/

/* Public Functions  ---------------------------------------------------------*/
void Boot_SendCmd( uint8_t* Data, uint8_t Length, Boot_StatusType Error )
{
	uint8_t length_cpy = Length;

	Boot_TxProtocol = ( Boot_TxProtocolType ){ 0 };
	Boot_TxProtocol.Sof = BOOT_HEADER_SOF;

	if( ( Error != OK ) || ( Length > BOOT_MAX_TX_DATA_LENGTH ) )
	{
		Boot_TxProtocol.Ack = BOOT_NACK;
		Boot_TxProtocol.Status = Error;
		Boot_TxProtocol.Length = 0;
	}
	else
	{
		Boot_TxProtocol.Ack = BOOT_ACK;
		Boot_TxProtocol.Status = OK;
		Boot_TxProtocol.Length = Length;
		memcpy(Boot_TxProtocol.Data, Data, length_cpy);
	}

	Uart_WriteFrame( ( uint8_t* )&Boot_TxProtocol, ( BOOT_TX_HEADER_LENGTH + Length ) );
}

Boot_RxProtocolType* Boot_ReadCmd( void )
{
	Boot_RxProtocolType* RxProtocol = NULL;

	/* Read Frame */
	if( ( Uart_ReadFrame( ( uint8_t* )&Boot_RxProtocol, BOOT_RX_HEADER ) == UART_RX_OK ) && ( Boot_RxProtocol.Sof == BOOT_HEADER_SOF ) )
	{
		RxProtocol = &Boot_RxProtocol;
	}

	printf("%d\n", Boot_RxProtocol.Cmd );
	return RxProtocol;
}

/* Private Functions  ---------------------------------------------------------*/
