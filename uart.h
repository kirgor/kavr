#pragma once

#include <stdint.h>

/**
 * ubrr - value of UBRR register to select UART mode.
 */
void initUart(uint16_t ubrr);

void uartWrite(uint8_t c);

uint8_t uartRead();

void uartWriteString(uint8_t *str);
