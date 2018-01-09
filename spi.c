#ifdef KAVR_FEATURE_SPI

#include <avr/io.h>

#ifdef SPCR

#include "spi.h"
#include "io.h"

void spi_slave_init() {
	port_b_output_mode(4);
	set_flags(SPCR, SPE);
}

void spi_master_init(uint8_t prescaler_mask) {
	port_b_output_mode(3, 5);
	SPCR |= mask(SPE, MSTR) | prescaler_mask;
}

uint8_t spi_byte_transaction(uint8_t out) {
	SPDR = out;
	while(!check_flag(SPSR, SPIF));
	return SPDR;
}

void spi_read(uint8_t *buffer, uint8_t len) {
	for (uint8_t i = 0; i < len; i++)
		buffer[i] = spi_byte_transaction(0);
}

void spi_write(uint8_t *buffer, uint8_t len) {
	for (uint8_t i = 0; i < len; i++)
		spi_byte_transaction(buffer[i]);
}

void spi_read_write(uint8_t *rx_buffer, uint8_t *tx_buffer, uint8_t len) {
	for (uint8_t i = 0; i < len; i++)
		rx_buffer[i] = spi_byte_transaction(tx_buffer[i]);
}

#endif

#endif
