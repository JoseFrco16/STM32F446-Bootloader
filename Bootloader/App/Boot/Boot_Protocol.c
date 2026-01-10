/**
 ******************************************************************************
 * @file       Boot_Protocol.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Boot.h"
#include "Uart.h"

/* Define --------------------------------------------------------------------*/
#define BOOT_ACK 0x06u
#define BOOT_NACK 0x15u
#define BOOT_MAX_REPLY_LENGTH 62u /* TX Buffer - ACK - Status */
#define BOOT_ACK_PLUS_STATUS_LENGTH 2u

/* Enum  ----------------------------------------------------------------------*/
enum Boot_Status{
	OK = 0,
	ERROR_GENERIC,
	ERROR_CRC,
	ERROR_MEMORY_ADDRESS
};

/* Typedef -------------------------------------------------------------------*/
typedef struct{
	uint8_t Sof;
	uint8_t Ack;
	uint8_t Status;
	uint8_t Length;
	uint8_t* Data;
	uint8_t Crc;
}Boot_ReplyType;

typedef enum Boot_Status Boot_StatusType;

/* Public variables ----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Public Functions  ---------------------------------------------------------*/
void Boot_SendReply( uint8_t* Data, uint8_t Length, Boot_StatusType Error )
{
	Boot_ReplyType boot_reply;
	uint8_t length_cpy = Length;

	if( ( Error != OK ) || ( Length > BOOT_MAX_REPLY_LENGTH ) )
	{
		boot_reply.Ack = BOOT_NACK;
		boot_reply.Status = Error;
		length_cpy = 0;
	}
	else
	{
		boot_reply.Ack = BOOT_ACK;
		boot_reply.Status = OK;
		boot_reply.Data = Data;
	}

	Uart_WriteFrame( boot_reply, ( BOOT_ACK_PLUS_STATUS_LENGTH + length_cpy ) );
}

/* Private Functions  ---------------------------------------------------------*/
