#ifdef KAVR_FEATURE_DS18B20

#include <avr/io.h>
#include <avr/interrupt.h>
#include "delay.h"
#include "ds18b20.h"

uint8_t ds18b20_reset(ds18b20_handle_t *handle) {
	handle->switch_output();
	handle->write(0);
	delay_us(480);

	handle->switch_input();
	delay_us(60);

	uint8_t value = handle->read();
	delay_us(420);

	return value;
}

void ds18b20_write_bit(ds18b20_handle_t *handle, uint8_t bit) {
	handle->switch_output();
	handle->write(0);
	delay_us(1);

	if (bit) {
		handle->switch_input();
	}
	delay_us(60);
	handle->switch_input();
}

uint8_t ds18b20_read_bit(ds18b20_handle_t *handle) {
	uint8_t bit = 0;

	handle->switch_output();
	handle->write(0);
	delay_us(1);

	handle->switch_input();
	delay_us(14);

	if (handle->read()) {
		bit = 1;
	}

	delay_us(45);

	return bit;
}

void ds18b20_write_byte(ds18b20_handle_t *handle, uint8_t byte) {
	uint8_t i = 8;
	while (i--) {
		ds18b20_write_bit(handle, byte & 1);
		byte >>= 1;
	}
}

uint8_t ds18b20_read_byte(ds18b20_handle_t *handle) {
	uint8_t i = 8, n = 0;
	while (i--) {
		n >>= 1;
		n |= (ds18b20_read_bit(handle) << 7);
	}
	return n;
}

double ds18b20_read(ds18b20_handle_t *handle) {
	ds18b20_reset(handle);
	ds18b20_write_byte(handle, 0xcc);
	ds18b20_write_byte(handle, 0x44);

	while (!ds18b20_read_bit(handle));

	ds18b20_reset(handle);
	ds18b20_write_byte(handle, 0xcc);
	ds18b20_write_byte(handle, 0xbe);

	uint8_t tl = ds18b20_read_byte(handle);
	uint8_t th = ds18b20_read_byte(handle);
	return ((th << 8) + tl) * 0.0625;
}

#endif
