#pragma once
#include <avr/io.h>

#ifdef SPCR

void initSpiSlave();

void initSpiMaster(uint8_t prescalerMask);

uint8_t spiByteTransaction(uint8_t out);

void spiRead(uint8_t *buffer, uint8_t len);

void spiWrite(uint8_t *buffer, uint8_t len);

void spiReadWrite(uint8_t *rxBuffer, uint8_t *txBuffer, uint8_t len);

#endif
