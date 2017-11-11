#include "uart.h"
#include "macros.h"
#include <avr/io.h>

void initUart(uint16_t ubrr) {
	UBRR0 = ubrr;
	setFlags(UCSR0C, UCSZ01, UCSZ00);
	setFlags(UCSR0B, RXEN0, TXEN0);
}

void uartWrite(uint8_t c) {
	while (!checkFlag(UCSR0A, UDRE0));
	UDR0 = c;
}

uint8_t uartRead() {
	while (!checkFlag(UCSR0A, RXC0));
	return UDR0;
}

void uartWriteString(uint8_t *str) {
	for (int i = 0; ; i++) {
		uint8_t c = str[i];
		if (c) {
			uartWrite(c);
		} else {
			break;
		}
	}
}
