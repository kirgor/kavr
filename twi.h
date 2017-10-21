#pragma once

#define TWI_STATUS_START			0x08
#define TWI_STATUS_REPEATED_START	0x10
#define TWI_STATUS_SLA_W_ACK		0x18
#define TWI_STATUS_SLA_W_NOT_ACK	0x20
#define TWI_STATUS_WRITE_ACK		0x28
#define TWI_STATUS_WRITE_NOT_ACK	0x30
#define TWI_STATUS_SLA_R_ACK		0x40
#define TWI_STATUS_SLA_R_NOT_ACK	0x48
#define TWI_STATUS_READ_ACK			0x50
#define TWI_STATUS_READ_NOT_ACK		0x58

void twiInit();
void twiStart();
void twiStop();
void twiWrite(char data);
char twiReadAck();
char twiReadNotAck();
char twiStatus();
