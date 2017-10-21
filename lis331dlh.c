#include "lis331dlh.h"
#include "twi.h"

#define LIS331DLH_SLA_W 0x30
#define LIS331DLH_SLA_R 0x31

char lis331dlh_readRegister(char address) {
	twiStart();
	twiWrite(LIS331DLH_SLA_W);
	twiWrite(address);
	twiStart();
	twiWrite(LIS331DLH_SLA_R);
	char value = twiReadNotAck();
	twiStop();
	return value;
}

void lis331dlh_writeRegister(char address, char data) {
	twiStart();
	twiWrite(LIS331DLH_SLA_W);
	twiWrite(address);
	twiWrite(data);
	twiStop();
}

char lis331dlh_whoAmI() {
	return lis331dlh_readRegister(0x0f);
}

void lis331dlh_init() {
	lis331dlh_writeRegister(0x20, 0b00100111);
}

uint16_t lis331dlh_readX() {
	return lis331dlh_readRegister(0x28) + (lis331dlh_readRegister(0x29) << 8);
}

uint16_t lis331dlh_readY() {
	return lis331dlh_readRegister(0x2a) + (lis331dlh_readRegister(0x2b) << 8);
}

uint16_t lis331dlh_readZ() {
	return lis331dlh_readRegister(0x2c) + (lis331dlh_readRegister(0x2d) << 8);
}
