#include <avr/io.h>

#ifdef SPCR

#include "spi.h"
#include "output.h"

void initSpiSlave() {
	initOutputB(4);
	setFlags(SPCR, SPE);
}

void initSpiMaster(uint8_t prescalerMask) {
	initOutputB(3, 5);
	SPCR |= mask(SPE, MSTR) | prescalerMask;
}

uint8_t spiByteTransaction(uint8_t out) {
	SPDR = out;
	while(!checkFlag(SPSR, SPIF));
	return SPDR;
}

void spiRead(uint8_t *buffer, uint8_t len) {
	for (uint8_t i = 0; i < len; i++)
		buffer[i] = spiByteTransaction(0);
}

void spiWrite(uint8_t *buffer, uint8_t len) {
	for (uint8_t i = 0; i < len; i++)
		spiByteTransaction(buffer[i]);
}

void spiReadWrite(uint8_t *rxBuffer, uint8_t *txBuffer, uint8_t len) {
	for (uint8_t i = 0; i < len; i++)
		rxBuffer[i] = spiByteTransaction(txBuffer[i]);
}

#endif
