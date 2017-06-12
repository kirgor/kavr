#include <avr/io.h>

#ifdef SPCR
#include "spi.h"
#include "output.h"

void initSpiSlave() {
	initOutputB(4);
	setFlags(SPCR, SPE);
}

void initSpiMaster(char prescalerMask) {
	initOutputB(3, 5);
	SPCR |= mask(SPE, MSTR) | prescalerMask;
}

unsigned char spiByteTransaction(unsigned char out) {
	SPDR = out;
	while(!checkFlag(SPSR, SPIF));
	return SPDR;
}

void spiRead(unsigned char *buffer, unsigned int len) {
	for (unsigned int i = 0; i < len; i++)
		buffer[i] = spiByteTransaction(0);
}

void spiWrite(unsigned char *buffer, unsigned int len) {
	for (unsigned int i = 0; i < len; i++)
		spiByteTransaction(buffer[i]);
}

void spiReadWrite(unsigned char *rxBuffer, unsigned char *txBuffer, unsigned int len) {
	for (unsigned int i = 0; i < len; i++)
		rxBuffer[i] = spiByteTransaction(txBuffer[i]);
}
#endif
