#pragma once
#include <stdint.h>

typedef struct {
	void (*switchInput)();
	void (*switchOutput)();
	uint8_t (*read)();
	void (*write)(uint8_t value);
} ds18b20_handle;

double ds18b20_read(ds18b20_handle *handle);
