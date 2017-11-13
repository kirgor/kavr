#include "ds18b20.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "delay.h"

uint8_t ds18b20_reset(ds18b20_handle *handle) {
	handle->switchOutput();
	handle->write(0);
	delayUs(480);

	handle->switchInput();
	delayUs(60);

	uint8_t value = handle->read();
	delayUs(420);

	return value;
}

void ds18b20_writeBit(ds18b20_handle *handle, uint8_t bit) {
	handle->switchOutput();
	handle->write(0);
	delayUs(1);

	if (bit) {
		handle->switchInput();
	}
	delayUs(60);
	handle->switchInput();
}

uint8_t ds18b20_readBit(ds18b20_handle *handle) {
	uint8_t bit = 0;

	handle->switchOutput();
	handle->write(0);
	delayUs(1);

	handle->switchInput();
	delayUs(14);

	if (handle->read()) {
		bit = 1;
	}

	delayUs(45);

	return bit;
}

void ds18b20_writeByte(ds18b20_handle *handle, uint8_t byte) {
	uint8_t i = 8;
	while (i--) {
		ds18b20_writeBit(handle, byte & 1);
		byte >>= 1;
	}
}

uint8_t ds18b20_readByte(ds18b20_handle *handle) {
	uint8_t i = 8, n = 0;
	while (i--) {
		n >>= 1;
		n |= (ds18b20_readBit(handle) << 7);
	}
	return n;
}

double ds18b20_read(ds18b20_handle *handle) {
	ds18b20_reset(handle);
	ds18b20_writeByte(handle, 0xcc);
	ds18b20_writeByte(handle, 0x44);

	while (!ds18b20_readBit(handle));

	ds18b20_reset(handle);
	ds18b20_writeByte(handle, 0xcc);
	ds18b20_writeByte(handle, 0xbe);

	uint8_t tl = ds18b20_readByte(handle);
	uint8_t th = ds18b20_readByte(handle);
	return ((th << 8) + tl) * 0.0625;
}

