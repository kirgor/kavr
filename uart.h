#pragma once

#include <stdint.h>

/**
 * ubrr - value of UBRR register to select UART mode.
 */
void initUart(uint16_t ubrr);

void uartWrite(char c);

char uartRead();

void uartWriteString(char* str);
