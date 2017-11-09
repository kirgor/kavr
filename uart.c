#include "uart.h"
#include "macros.h"
#include <avr/io.h>

void initUart(uint16_t ubrr) {
	UBRR0 = ubrr;
	setFlags(UCSR0C, UCSZ01, UCSZ00);
	setFlags(UCSR0B, RXEN0, TXEN0);
}

void uartWrite(char c) {
	while (!checkFlag(UCSR0A, UDRE0));
	UDR0 = c;
}

char uartRead() {
	while (!checkFlag(UCSR0A, RXC0));
	return UDR0;
}

void uartWriteString(char* str) {
	for (int i = 0; ; i++) {
		char c = str[i];
		if (c) {
			uartWrite(c);
		} else {
			break;
		}
	}
}
