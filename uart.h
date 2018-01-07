#pragma once
#include <stdint.h>

#define UBRR_16_9600 0x067

/**
 * ubrr - value of UBRR register to select UART mode.
 */
void uart_init(uint16_t ubrr);

void uart_write(uint8_t c);

uint8_t uart_read();

void uart_write_string(uint8_t *str);
