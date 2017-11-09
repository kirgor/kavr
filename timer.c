#include "timer.h"
#include "macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void (*timer1CTCHandler)();

void initTimer1CTC(char csMask, int ocr, void (*handler)()) {
	timer1CTCHandler = handler;

	cli();
	setFlags(TCCR1B, WGM12);
	setFlags(TIMSK1, OCIE1A);
	TCCR1B |= csMask;
	OCR1A = ocr;
	sei();
}

ISR(TIMER1_COMPA_vect) {
	timer1CTCHandler();
}
