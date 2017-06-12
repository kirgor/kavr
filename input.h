#pragma once
#include "macros.h"

#define initInputB(...) unsetFlags(DDRB, __VA_ARGS__); unsetFlags(PORTB, __VA_ARGS__)
#define initInputC(...) unsetFlags(DDRC, __VA_ARGS__); unsetFlags(PORTC, __VA_ARGS__)
#define initInputD(...) unsetFlags(DDRD, __VA_ARGS__); unsetFlags(PORTD, __VA_ARGS__)
#define initPullupInputB(...) unsetFlags(DDRB, __VA_ARGS__); setFlags(PORTB, __VA_ARGS__)
#define initPullupInputC(...) unsetFlags(DDRC, __VA_ARGS__); setFlags(PORTC, __VA_ARGS__)
#define initPullupInputD(...) unsetFlags(DDRD, __VA_ARGS__); setFlags(PORTD, __VA_ARGS__)
#define readInputB(bit) (!!checkFlag(PINB, bit))
#define readInputC(bit) (!!checkFlag(PINC, bit))
#define readInputD(bit) (!!checkFlag(PIND, bit))
