#ifdef KAVR_FEATURE_TWI

#include "twi.h"
#include "macros.h"
#include <avr/io.h>

void twi_init() {
    TWSR = 0x00;
    TWBR = 0x0C;
    TWCR = mask(TWEN);
}

void twi_start() {
    TWCR = mask(TWINT, TWSTA, TWEN);
    while (!check_flag(TWCR, TWINT));
}

void twi_stop() {
    TWCR = mask(TWINT, TWSTO, TWEN);
}

void twi_write(uint8_t data) {
    TWDR = data;
    TWCR = mask(TWINT, TWEN);
    while (!check_flag(TWCR, TWINT));
}

uint8_t twi_read_ack() {
    TWCR = mask(TWINT, TWEA, TWEN);
    while (!check_flag(TWCR, TWINT));
    return TWDR;
}

uint8_t twi_read_not_ack() {
	TWCR = mask(TWINT, TWEN);
	while (!check_flag(TWCR, TWINT));
	return TWDR;
}

uint8_t twi_status() {
    return TWSR & 0xF8;
}

#endif
