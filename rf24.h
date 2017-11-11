#pragma once
#include <stdint.h>

#define RF24_DIRECTION_TRANSMIT		0
#define RF24_DIRECTION_RECEIVE		1

typedef struct {
	void (*writeCe)(uint8_t value);
	void (*writeCsn)(uint8_t value);
} rf24_handle;

void rf24_init(rf24_handle *handle);

uint8_t rf24_readRegisterByte(rf24_handle *handle, uint8_t address);

void rf24_writeRegisterByte(rf24_handle *handle, uint8_t address, uint8_t data);

void rf24_readRegister(rf24_handle *handle, uint8_t address, uint8_t *buffer, uint8_t len);

void rf24_writeRegister(rf24_handle *handle, uint8_t address, uint8_t *buffer, uint8_t len);

void rf24_writeRegisterBit(rf24_handle *handle, uint8_t address, uint8_t bitIndex, uint8_t bitValue);

void rf24_power(rf24_handle *handle, uint8_t power);

void rf24_direction(rf24_handle *handle, uint8_t direction);

void rf24_listen(rf24_handle *handle, uint8_t listen);

void rf24_getRxAddress(rf24_handle *handle, uint8_t pipe, uint8_t *address, uint8_t len);

void rf24_setRxAddress(rf24_handle *handle, uint8_t pipe, uint8_t *address, uint8_t len);

void rf24_getTxAddress(rf24_handle *handle, uint8_t *address, uint8_t len);

void rf24_setTxAddress(rf24_handle *handle, uint8_t *address, uint8_t len);

uint8_t rf24_getPayloadWidth(rf24_handle *handle, uint8_t pipe);

void rf24_setPayloadWidth(rf24_handle *handle, uint8_t pipe, uint8_t width);

uint8_t rf24_readEnabledRxMask(rf24_handle *handle);

void rf24_writeEnabledRxMask(rf24_handle *handle, uint8_t mask);

void rf24_receive(rf24_handle *handle, uint8_t *buffer, uint8_t len);

void rf24_transmit(rf24_handle *handle, uint8_t *buffer, uint8_t len);
