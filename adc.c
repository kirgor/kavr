#include "adc.h"
#include "macros.h"
#include <avr/io.h>

void initADC(int psMask) {
	ADCSRA = mask(ADEN) | psMask;
}

unsigned int readADC(int channel) {
	ADMUX = mask(REFS0) | 1;
	setFlag(ADCSRA, ADSC);
	while (checkFlag(ADCSRA, ADSC));
	return ADCW;
}
