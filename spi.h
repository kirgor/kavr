#ifdef KAVR_FEATURE_SPI

#pragma once
#include "macros.h"
#include <avr/io.h>

#ifdef SPCR

#define SPI_PRESCALER_4		0
#define SPI_PRESCALER_16	mask(SPR0)
#define SPI_PRESCALER_64	mask(SPR1)
#define SPI_PRESCALER_128	mask(SPR0, SPR1)

void spi_slave_init();

void spi_master_init(uint8_t prescaler_mask);

uint8_t spi_byte_transaction(uint8_t out);

void spi_read(uint8_t *buffer, uint8_t len);

void spi_write(uint8_t *buffer, uint8_t len);

void spi_read_write(uint8_t *rx_buffer, uint8_t *tx_buffer, uint8_t len);

#endif

#endif
