#ifdef KAVR_FEATURE_DS18B20

#pragma once
#include <stdint.h>

typedef struct {
	void (*switch_input)();
	void (*switch_output)();
	uint8_t (*read)();
	void (*write)(uint8_t value);
} ds18b20_handle_t;

double ds18b20_read(ds18b20_handle_t *handle);

#endif
