#include "ultrasound.h"
#include "delay.h"

#ifndef ULTRASOUND_LOOP_DELAY
#define ULTRASOUND_LOOP_DELAY 64
#endif

#ifndef ULTRASOUND_LOOP_OVERHEAD
#define ULTRASOUND_LOOP_OVERHEAD 10
#endif

double ultraSoundRead(ultra_sound_handle *handle) {
	handle->writeTrigger(1);
	delayUs(20);
	handle->writeTrigger(0);

	uint8_t echo = 0;
	while (!echo) {
		echo = handle->readEcho();
	}

	uint16_t ticks = 0;
	while (echo) {
		delayLoop2(ULTRASOUND_LOOP_DELAY);
		ticks++;
		echo = handle->readEcho();
	}

	double timeInSeconds = (1.0 / F_CPU) * ticks * (ULTRASOUND_LOOP_DELAY * 4 + ULTRASOUND_LOOP_OVERHEAD);
	return 340.29 * timeInSeconds / 2;
}
