#include "uart.h"
#include "macros.h"
#include <avr/io.h>

void uart_init(uint16_t ubrr) {
	UBRR0 = ubrr;
	set_flags(UCSR0C, UCSZ01, UCSZ00);
	set_flags(UCSR0B, RXEN0, TXEN0);
}

void uart_write(uint8_t c) {
	while (!check_flag(UCSR0A, UDRE0));
	UDR0 = c;
}

uint8_t uart_read() {
	while (!check_flag(UCSR0A, RXC0));
	return UDR0;
}

void uart_write_string(uint8_t *str) {
	for (int i = 0; ; i++) {
		uint8_t c = str[i];
		if (c) {
			uart_write(c);
		} else {
			break;
		}
	}
}
