#pragma once
#include <stdint.h>

typedef struct {
	void (*write_ce)(uint8_t value);
	void (*write_csn)(uint8_t value);
	uint8_t *slave_address;
	uint8_t *master_address;
	uint8_t *request_buffer;
	uint8_t request_length;
	void (*request_handler)();
} rf24_slave_t;

void rf24_read_register(uint8_t address, uint8_t *buffer, uint8_t len);

void rf24_write_register(uint8_t address, uint8_t *buffer, uint8_t len);

uint8_t rf24_read_register_byte(uint8_t address);

void rf24_write_register_byte(uint8_t address, uint8_t data);

void rf24_pins_init();

void rf24_registers_init(uint8_t *slave_address, uint8_t *master_address, uint8_t request_length);

uint8_t rf24_receive(uint8_t *buffer, uint8_t len);

uint8_t rf24_transmit(uint8_t *buffer, uint8_t len);

void rf24_slave_tick(uint8_t *buffer, uint8_t request_length, void (*request_handler)());

uint8_t rf24_slave_respond(uint8_t *data, uint8_t len);
