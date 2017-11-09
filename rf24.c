#include "rf24.h"
#include "macros.h"
#include "spi.h"

void rf24ReadRegister(rf24_handle *handle, uint8_t address, uint8_t *buffer, uint8_t len) {
	handle->writeCsn(0);
	spiByteTransaction(address);
	spiRead(buffer, len);
	handle->writeCsn(1);
}

void rf24WriteRegister(rf24_handle *handle, uint8_t address, uint8_t *buffer, uint8_t len) {
	handle->writeCsn(0);
	spiByteTransaction(0b100000 | address);
	spiWrite(buffer, len);
	handle->writeCsn(1);
}

void rf24SetRegisterBit(rf24_handle *handle, uint8_t address, uint8_t bit) {
	unsigned char data;
	rf24ReadRegister(handle, address, &data, 1);
	setFlag(data, bit);
	rf24WriteRegister(handle, address, &data, 1);
}

void rf24UnsetRegisterBit(rf24_handle *handle, uint8_t address, uint8_t bit) {
	unsigned char data;
	rf24ReadRegister(handle, address, &data, 1);
	unsetFlag(data, bit);
	rf24WriteRegister(handle, address, &data, 1);
}

void rf24StartReceiving(rf24_handle *handle) {
	handle->writeCe(1);
}

void rf24StopReceiving(rf24_handle *handle) {
	handle->writeCe(0);
}

void rf24PowerUp(rf24_handle *handle) {
	rf24SetRegisterBit(handle, 0x00, 1);
}

void rf24SetRxMode(rf24_handle *handle) {
	rf24SetRegisterBit(handle, 0x00, 0);
}

void rf24SetTxMode(rf24_handle *handle) {
	rf24UnsetRegisterBit(handle, 0x00, 0);
}
