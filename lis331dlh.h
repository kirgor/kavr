#pragma once
#include <stdint.h>

uint8_t lis331dlh_readRegister(uint8_t address);

void lis331dlh_writeRegister(uint8_t address, uint8_t data);

uint8_t lis331dlh_whoAmI();

void lis331dlh_init();

int16_t lis331dlh_readX();

int16_t lis331dlh_readY();

int16_t lis331dlh_readZ();
