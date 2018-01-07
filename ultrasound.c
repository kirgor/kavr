#include "ultrasound.h"
#include "delay.h"

#ifndef ULTRASOUND_LOOP_DELAY
#define ULTRASOUND_LOOP_DELAY 64
#endif

#ifndef ULTRASOUND_LOOP_OVERHEAD
#define ULTRASOUND_LOOP_OVERHEAD 10
#endif

double ultrasound_read(ultrasound_handle_t *handle) {
	handle->write_trigger(1);
	delay_us(20);
	handle->write_trigger(0);

	uint8_t echo = 0;
	while (!echo) {
		echo = handle->read_echo();
	}

	uint16_t ticks = 0;
	while (echo) {
		delay_loop_2(ULTRASOUND_LOOP_DELAY);
		ticks++;
		echo = handle->read_echo();
	}

	double timeInSeconds = (1.0 / F_CPU) * ticks * (ULTRASOUND_LOOP_DELAY * 4 + ULTRASOUND_LOOP_OVERHEAD);
	return 340.29 * timeInSeconds / 2;
}
