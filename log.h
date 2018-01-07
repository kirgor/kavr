#pragma once

#ifdef LOG_ENABLED

#include "uart.h"
#include <stdio.h>

char log_buffer[32];

#define log_init(ubrr) uart_init(ubrr)
#define log_write(str) uart_write_string(str); uart_write('\n')
#define log_write_format(format, ...) snprintf(log_buffer, 32, format, __VA_ARGS__); uart_write_string(log_buffer); uart_write('\n')

#else

#define log_init(ubrr)
#define log_write(str)
#define log_write_format(format, ...)

#endif
