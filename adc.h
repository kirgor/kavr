#ifdef KAVR_FEATURE_ADC

#pragma once
#include <stdint.h>

/**
 * ps_mask - ADC Prescaler Select Bits.
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
void adc_init(uint8_t ps_mask);

/**
 * channel - number of ADC channel (from 0 to 7).
 */
uint16_t adc_read(uint8_t channel);

#endif
