#include "twi.h"
#include "macros.h"
#include <avr/io.h>

void twiInit() {
    TWSR = 0x00;
    TWBR = 0x0C;
    TWCR = mask(TWEN);
}

void twiStart() {
    TWCR = mask(TWINT, TWSTA, TWEN);
    while (!checkFlag(TWCR, TWINT));
}

void twiStop() {
    TWCR = mask(TWINT, TWSTO, TWEN);
}

void twiWrite(uint8_t data) {
    TWDR = data;
    TWCR = mask(TWINT, TWEN);
    while (!checkFlag(TWCR, TWINT));
}

uint8_t twiReadAck() {
    TWCR = mask(TWINT, TWEA, TWEN);
    while (!checkFlag(TWCR, TWINT));
    return TWDR;
}

uint8_t twiReadNotAck() {
	TWCR = mask(TWINT, TWEN);
	while (!checkFlag(TWCR, TWINT));
	return TWDR;
}

uint8_t twiStatus() {
    return TWSR & 0xF8;
}
