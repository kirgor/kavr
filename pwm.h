#pragma once

#define writeFastPWMPD6(value) OCR0A=value
#define writeFastPWMPD5(value) OCR0B=value

void initFastPWM0(int portMask, int csMask);
