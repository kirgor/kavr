#include "rf24.h"
#include "macros.h"
#include "spi.h"
#include "delay.h"

void rf24_init(rf24_handle *handle) {
	handle->writeCsn(1);
}

uint8_t rf24_readRegisterByte(rf24_handle *handle, uint8_t address) {
	handle->writeCsn(0);
	spiByteTransaction(address);
	uint8_t data = spiByteTransaction(0);
	handle->writeCsn(1);
	return data;
}

void rf24_writeRegisterByte(rf24_handle *handle, uint8_t address, uint8_t data) {
	handle->writeCsn(0);
	spiByteTransaction(0b100000 | address);
	spiByteTransaction(data);
	handle->writeCsn(1);
}

void rf24_readRegister(rf24_handle *handle, uint8_t address, uint8_t *buffer, uint8_t len) {
	handle->writeCsn(0);
	spiByteTransaction(address);
	spiRead(buffer, len);
	handle->writeCsn(1);
}

void rf24_writeRegister(rf24_handle *handle, uint8_t address, uint8_t *buffer, uint8_t len) {
	handle->writeCsn(0);
	spiByteTransaction(0b100000 | address);
	spiWrite(buffer, len);
	handle->writeCsn(1);
}

void rf24_writeRegisterBit(rf24_handle *handle, uint8_t address, uint8_t bitIndex, uint8_t bitValue) {
	uint8_t data = rf24_readRegisterByte(handle, address);
	if (bitValue) {
		setFlag(data, bitIndex);
	} else {
		unsetFlag(data, bitIndex);
	}
	rf24_writeRegisterByte(handle, address, data);
}

void rf24_power(rf24_handle *handle, uint8_t power) {
	rf24_writeRegisterBit(handle, 0x00, 1, power);
}

void rf24_direction(rf24_handle *handle, uint8_t direction) {
	rf24_writeRegisterBit(handle, 0x00, 0, direction);
}

void rf24_listen(rf24_handle *handle, uint8_t listen) {
	handle->writeCe(listen);
}

void rf24_getRxAddress(rf24_handle *handle, uint8_t pipe, uint8_t *address, uint8_t len) {
	rf24_readRegister(handle, 0x0a + pipe, address, len);
}

void rf24_setRxAddress(rf24_handle *handle, uint8_t pipe, uint8_t *address, uint8_t len) {
	rf24_writeRegister(handle, 0x0a + pipe, address, len);
}

void rf24_getTxAddress(rf24_handle *handle, uint8_t *address, uint8_t len) {
	rf24_readRegister(handle, 0x10, address, len);
}

void rf24_setTxAddress(rf24_handle *handle, uint8_t *address, uint8_t len) {
	rf24_writeRegister(handle, 0x10, address, len);
}

uint8_t rf24_getPayloadWidth(rf24_handle *handle, uint8_t pipe) {
	return rf24_readRegisterByte(handle, 0x11 + pipe);
}

void rf24_setPayloadWidth(rf24_handle *handle, uint8_t pipe, uint8_t width) {
	rf24_writeRegisterByte(handle, 0x11 + pipe, width);
}

uint8_t rf24_readEnabledRxMask(rf24_handle *handle) {
	return rf24_readRegisterByte(handle, 0x02);
}

void rf24_writeEnabledRxMask(rf24_handle *handle, uint8_t mask) {
	rf24_writeRegisterByte(handle, 0x02, mask);
}

void rf24_waitStatusFlag(rf24_handle *handle, uint8_t bit) {
	uint8_t status;
	do rf24_readRegister(handle, 0x07, &status, 1); while(!checkFlag(status, bit));
	rf24_writeRegister(handle, 0x07, &status, 1);
}

void rf24_receive(rf24_handle *handle, uint8_t *buffer, uint8_t len) {
	rf24_waitStatusFlag(handle, 6);
	rf24_readRegister(handle, 0x61, buffer, len);
}

void rf24_transmit(rf24_handle *handle, uint8_t *buffer, uint8_t len) {
	rf24_writeRegister(handle, 0xa0, buffer, len);
	handle->writeCe(1);
	delayUs(20);
	handle->writeCe(0);
	rf24_waitStatusFlag(handle, 5);
}
