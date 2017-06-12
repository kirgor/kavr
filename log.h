#pragma once

#ifdef LOG
#include "uart.h"
#include <stdio.h>
char logBuffer[32];
#define initLog(ubrr) initUart(ubrr)
#define log(str) uartWriteString(str); uartWrite('\n')
#define logFormat(format, ...) snprintf(logBuffer, 32, format, __VA_ARGS__); uartWriteString(logBuffer); uartWrite('\n')
#else
#define initLog(ubrr)
#define log(str)
#define logFormat(format, ...)
#endif
