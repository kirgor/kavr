#pragma once

#include <stdint.h>

#define writeFastPwmPD6(value) OCR0A=value

#define writeFastPwmPD5(value) OCR0B=value

/**
 * Initialize PWM channel 0.
 * portMask - PORTD mask to enable output for selected ports.
 * csMask - clock select mask. Possible values:
 * bit2		bit1	bit0	clock
 * ------------------------------
 * 0		0		0		disabled
 * 0		0		1		IO clock with no prescaling
 * 0		1		0		IO clock / 8 prescaling
 * 0		1		1		IO clock / 64 prescaling
 * 1		0		0		IO clock / 256 prescaling
 * 1		0		1		IO clock / 1024 prescaling
 * 1		1		0		External clock source on T0 pin. Clock on falling edge.
 * 1		1		1		External clock source on T0 pin. Clock on rising edge.
 */
void initFastPwm0(uint8_t portMask, uint8_t csMask);
