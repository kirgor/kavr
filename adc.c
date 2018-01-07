#include "adc.h"
#include "macros.h"
#include <avr/io.h>

void adc_init(uint8_t ps_mask) {
	ADCSRA = mask(ADEN) | ps_mask;
}

uint16_t adc_read(uint8_t channel) {
	ADMUX = mask(REFS0) | channel;
	set_flag(ADCSRA, ADSC);
	while (check_flag(ADCSRA, ADSC));
	return ADCW;
}
