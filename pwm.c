#ifdef KAVR_FEATURE_PWM

#include "pwm.h"
#include "io.h"
#include <avr/io.h>

void pwm_0_init(uint8_t prescaler_mask) {
	port_d_output_mode(5, 6);
	set_flags(TCCR0A, COM0A1, COM0B1, WGM00);
	TCCR0B |= prescaler_mask;
}

void pwm_1_init(uint8_t prescaler_mask) {
	port_b_output_mode(1, 2);
	set_flags(TCCR1A, COM1A1, COM1B1, WGM10);
	TCCR1B |= prescaler_mask;
}

#endif
