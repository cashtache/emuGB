#pragma once

// emuGB
#include "common.h"

// Reads from the address bus
uint8_t bus_read(uint16_t addr);
// Writes to the address bus
void bus_write(uint16_t addr, uint8_t val);
