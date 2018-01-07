#include "pwm.h"
#include "io.h"
#include <avr/io.h>

void pwm_0_init(uint8_t prescaler_mask) {
	port_d_output_mode(5, 6);
	set_flags(TCCR0A, COM0A1, COM0B1, WGM00/*, WGM01*/);
	TCCR0B |= prescaler_mask;
}
