#include "lis331dlh.h"
#include "twi.h"

#define LIS331DLH_SLA_W 0x30
#define LIS331DLH_SLA_R 0x31

uint8_t lis331dlh_read_register(uint8_t address) {
	twi_start();
	twi_write(LIS331DLH_SLA_W);
	twi_write(address);
	twi_start();
	twi_write(LIS331DLH_SLA_R);
	uint8_t value = twi_read_not_ack();
	twi_stop();
	return value;
}

void lis331dlh_write_register(uint8_t address, uint8_t data) {
	twi_start();
	twi_write(LIS331DLH_SLA_W);
	twi_write(address);
	twi_write(data);
	twi_stop();
}

uint8_t lis331dlh_who_am_i() {
	return lis331dlh_read_register(0x0f);
}

void lis331dlh_init() {
	lis331dlh_write_register(0x20, 0b00100111);
}

int16_t lis331dlh_read_x() {
	return lis331dlh_read_register(0x28) + (lis331dlh_read_register(0x29) << 8);
}

int16_t lis331dlh_read_y() {
	return lis331dlh_read_register(0x2a) + (lis331dlh_read_register(0x2b) << 8);
}

int16_t lis331dlh_read_z() {
	return lis331dlh_read_register(0x2c) + (lis331dlh_read_register(0x2d) << 8);
}
