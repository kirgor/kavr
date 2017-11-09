#include "lis331dlh.h"
#include "twi.h"

#define LIS331DLH_SLA_W 0x30
#define LIS331DLH_SLA_R 0x31

uint8_t lis331dlh_readRegister(uint8_t address) {
	twiStart();
	twiWrite(LIS331DLH_SLA_W);
	twiWrite(address);
	twiStart();
	twiWrite(LIS331DLH_SLA_R);
	char value = twiReadNotAck();
	twiStop();
	return value;
}

void lis331dlh_writeRegister(uint8_t address, uint8_t data) {
	twiStart();
	twiWrite(LIS331DLH_SLA_W);
	twiWrite(address);
	twiWrite(data);
	twiStop();
}

uint8_t lis331dlh_whoAmI() {
	return lis331dlh_readRegister(0x0f);
}

void lis331dlh_init() {
	lis331dlh_writeRegister(0x20, 0b00100111);
}

int16_t lis331dlh_readX() {
	return lis331dlh_readRegister(0x28) + (lis331dlh_readRegister(0x29) << 8);
}

int16_t lis331dlh_readY() {
	return lis331dlh_readRegister(0x2a) + (lis331dlh_readRegister(0x2b) << 8);
}

int16_t lis331dlh_readZ() {
	return lis331dlh_readRegister(0x2c) + (lis331dlh_readRegister(0x2d) << 8);
}
