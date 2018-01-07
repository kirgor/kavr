#pragma once
#include <stdint.h>

typedef struct {
	void (*write_trigger)(uint8_t value);
	uint8_t (*read_echo)();
} ultrasound_handle_t;

double ultrasound_read(ultrasound_handle_t *handle);
