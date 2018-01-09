#ifdef KAVR_FEATURE_RF24

#include "rf24.h"
#include "io.h"
#include "spi.h"
#include "delay.h"

#define rf24_ce_low(...) CONCAT(KAVR_RF24_CE_PIN, _low())
#define rf24_ce_high(...) CONCAT(KAVR_RF24_CE_PIN, _high())
#define rf24_csn_low(...) CONCAT(KAVR_RF24_CSN_PIN, _low())
#define rf24_csn_high(...) CONCAT(KAVR_RF24_CSN_PIN, _high())

void rf24_read_register(uint8_t address, uint8_t *buffer, uint8_t len) {
	rf24_csn_low();
	spi_byte_transaction(address);
	spi_read(buffer, len);
	rf24_csn_high();
}

void rf24_write_register(uint8_t address, uint8_t *buffer, uint8_t len) {
	rf24_csn_low();
	spi_byte_transaction(0b100000 | address);
	spi_write(buffer, len);
	rf24_csn_high();
}

uint8_t rf24_read_register_byte(uint8_t address) {
	rf24_csn_low();
	spi_byte_transaction(address);
	uint8_t data = spi_byte_transaction(0);
	rf24_csn_high();
	return data;
}

void rf24_write_register_byte(uint8_t address, uint8_t data) {
	rf24_csn_low();
	spi_byte_transaction(0b100000 | address);
	spi_byte_transaction(data);
	rf24_csn_high();
}

void rf24_pins_init() {
	CONCAT(KAVR_RF24_CE_PIN, _output_mode());
	CONCAT(KAVR_RF24_CSN_PIN, _output_mode());
	rf24_ce_low();
	rf24_csn_high();
}

void rf24_registers_init(uint8_t *slave_address, uint8_t *master_address, uint8_t request_length) {
	// Power off
	rf24_write_register_byte(0x00, 0b1000);
	// Set TX address and RX address on pipe 0
	rf24_write_register(0x10, master_address, 5);
	rf24_write_register(0x0a, master_address, 5);
	// Set RX address on pipe 1
	rf24_write_register(0x0b, slave_address, 5);
	// Set payload width for pipe 1
	rf24_write_register_byte(0x12, request_length);
	// Set max amount of retries (15)
	rf24_write_register_byte(0x04, 0xff);
	// Power on and enter RX mode
	rf24_write_register_byte(0x00, 0b1011);
}

uint8_t rf24_receive(uint8_t *buffer, uint8_t len) {
	rf24_ce_high();

	while (1) {
		uint8_t status = rf24_read_register_byte(0x07);
		if (check_flag(status, 6)) {
			rf24_ce_low();
			rf24_write_register_byte(0x07, 0xff);
			rf24_read_register(0x61, buffer, len);
			return 0;
		}
	}
}

uint8_t rf24_transmit(uint8_t *buffer, uint8_t len) {
	rf24_write_register_byte(0x00, 0b1010);
	rf24_write_register(0xa0, buffer, len);

	rf24_ce_high();
	delay_us(20);
	rf24_ce_low();

	uint8_t error = 0;
	uint8_t status;
	while (1) {
		rf24_read_register(0x07, &status, 1);
		if (check_flag(status, 4)) {
			error = 1;
			break;
		}
		if (check_flag(status, 5)) {
			break;
		}
	}
	rf24_write_register_byte(0x07, 0xff);
	rf24_write_register(0xe1, 0, 0);
	rf24_write_register_byte(0x00, 0b1011);

	return error;
}

#endif
