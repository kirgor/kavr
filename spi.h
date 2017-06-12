#pragma once
#include <avr/io.h>

#ifdef SPCR
void initSpiSlave();
void initSpiMaster(char prescalerMask);
unsigned char spiByteTransaction(unsigned char out);
void spiRead(unsigned char *buffer, unsigned int len);
void spiWrite(unsigned char *buffer, unsigned int len);
void spiReadWrite(unsigned char *rxBuffer, unsigned char *txBuffer, unsigned int len);
#endif
