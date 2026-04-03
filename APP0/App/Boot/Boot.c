/**
 ******************************************************************************
 * @file       Boot.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Boot.h"
#include "Boot_ProtocolTypes.h"
#include "Boot_AppHeaderFlags.h"
#include "Mcu.h"

/* Define --------------------------------------------------------------------*/

/* Enum  ----------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
Boot_RxProtocolType Boot_RxProtocol;
HEADER_SECTION Boot_HeaderFlagsType Boot_HeaderFlags =
{
	.ota_flag = False,
    .magic   = BOOT_MAGIC_NUMBER,
    .size    = 0u,
    .crc     = 0u,
    .version = 0u
};

/* Private function prototypes -----------------------------------------------*/
/**
 * @brief Check ping command reception
 * @retval True  Ping command is received
 * @retval False Ping command is not received
 */
Bool_Type Boot_IsPingCmd( void );

/**
 * @brief Send ACK command to host
 */
void Boot_SendAckCmd( void );

/* Public Functions  ---------------------------------------------------------*/
void Boot_CheckBootRequest( void )
{
	if( Boot_IsPingCmd() == True )
	{
		Boot_HeaderFlags.ota_flag = True;
		Boot_SendAckCmd();
		Mcu_Reset();
	}
}

/* Private Functions  ---------------------------------------------------------*/
Bool_Type Boot_IsPingCmd( void )
{
	Bool_Type is_ping_cmd = False;

	/* Read Frame */
	if( ( Uart_ReadFrameIrq( ( uint8_t* )&Boot_RxProtocol, BOOT_RX_HEADER ) == UART_RX_OK ) &&
		( Boot_RxProtocol.Sof == BOOT_HEADER_SOF ) &&
		( Boot_RxProtocol.Cmd == PING ) )
	{
		is_ping_cmd = True;
	}

	return is_ping_cmd;
}

void Boot_SendAckCmd( void )
{
	Boot_TxProtocolType boot_tx_protocol;

	boot_tx_protocol = ( Boot_TxProtocolType ){ 0 };

	boot_tx_protocol.Sof = BOOT_HEADER_SOF;
	boot_tx_protocol.Ack = BOOT_ACK;
	boot_tx_protocol.Status = OK;
	boot_tx_protocol.Length = 0u;

	Uart_WriteFrame( ( uint8_t* )&boot_tx_protocol, BOOT_TX_HEADER_LENGTH );
}
