#pragma once
#include <stdint.h>

char lis331dlh_readRegister(char address);
void lis331dlh_writeRegister(char address, char data);
char lis331dlh_whoAmI();
void lis331dlh_init();
uint16_t lis331dlh_readX();
uint16_t lis331dlh_readY();
uint16_t lis331dlh_readZ();
