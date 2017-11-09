#pragma once
#include <stdint.h>

typedef struct {
	void (*writeCe)(uint8_t value);
	void (*writeCsn)(uint8_t value);
} rf24_handle;

void rf24ReadRegister(rf24_handle *handle, uint8_t address, uint8_t *buffer, uint8_t len);

void rf24WriteRegister(rf24_handle *handle, uint8_t address, uint8_t *buffer, uint8_t len);

void rf24SetRegisterBit(rf24_handle *handle, uint8_t address, uint8_t bit);

void rf24UnsetRegisterBit(rf24_handle *handle, uint8_t address, uint8_t bit);

void rf24StartReceiving(rf24_handle *handle);

void rf24StopReceiving(rf24_handle *handle);

void rf24PowerUp(rf24_handle *handle);

void rf24SetRxMode(rf24_handle *handle);

void rf24SetTxMode(rf24_handle *handle);
