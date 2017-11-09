#pragma once

#include <stdint.h>

/**
 * psMask - ADC Prescaler Select Bits.
 * Possible values:
 * bit2		bit1	bit0	division factor
 * ----------------------------------------
 * 0		0		0		2
 * 0		0		1		2
 * 0		1		0		4
 * 0		1		1		8
 * 1		0		0		16
 * 1		0		1		32
 * 1		1		0		64
 * 1		1		1 		128
 */
void initADC(uint8_t psMask);

/**
 * channel - number of ADC channel (from 0 to 7).
 */
uint16_t readADC(uint8_t channel);
