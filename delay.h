#pragma once

#include <util/delay.h>

/**
 * ms - number of milliseconds to sleep.
 */
#define delayMs(ms) _delay_ms(ms)

/**
 * us - number of microseconds to sleep.
 */
#define delayUs(us) _delay_us(us)

/**
 * count - number of loops to sleep (8-bit number). Each loop takes 3 CPU cycles.
 */
#define delayLoop1(count) _delay_loop_1(count)

/**
 * count - number of loops to sleep (16-bit number). Each loop takes 4 CPU cycles.
 */
#define delayLoop2(count) _delay_loop_2(count)
