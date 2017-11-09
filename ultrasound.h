#pragma once
#include <stdint.h>

typedef struct {
	void (*writeTrigger)(uint8_t value);
	uint8_t (*readEcho)();
} ultra_sound_handle;

/**
 * writeTrigger - function, which writes into trigger line.
 * readEcho - function, which reads echo line.
 * Returns measured distance in meters.
 */
double ultraSoundRead(ultra_sound_handle *handle);
