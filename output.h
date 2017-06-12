#pragma once
#include "macros.h"

#define initOutputB(...) setFlags(DDRB, __VA_ARGS__)
#define initOutputC(...) setFlags(DDRC, __VA_ARGS__)
#define initOutputD(...) setFlags(DDRD, __VA_ARGS__)
#define writeOutputB(bit, value) unsetFlag(PORTB, bit); PORTB |= value << bit
#define writeOutputC(bit, value) unsetFlag(PORTC, bit); PORTC |= value << bit
#define writeOutputD(bit, value) unsetFlag(PORTD, bit); PORTD |= value << bit
