#include "adc.h"
#include "macros.h"
#include <avr/io.h>

void initADC(uint8_t psMask) {
	ADCSRA = mask(ADEN) | psMask;
}

uint16_t readADC(uint8_t channel) {
	ADMUX = mask(REFS0) | channel;
	setFlag(ADCSRA, ADSC);
	while (checkFlag(ADCSRA, ADSC));
	return ADCW;
}
