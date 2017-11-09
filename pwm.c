#include "pwm.h"
#include "macros.h"
#include <avr/io.h>

void initFastPwm0(uint8_t portMask, uint8_t csMask) {
	DDRD |= portMask;
	setFlags(TCCR0A, COM0A1, COM0B1, WGM00, WGM01);
	TCCR0B |= csMask;
}
