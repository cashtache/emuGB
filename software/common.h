#pragma once

// Standard
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Check if the 'n'-th bit of 'a' is set
#define BIT(a, n) ((a & (1 << n)) ? 1 : 0)
// Set or clear the 'n'-th bit of 'a' based on 'on'
#define BIT_SET(a, n, on) (on ? a |= (1 << n) : a &= ~(1 << n))
// Check if 'a' is within the range ['b', 'c']
#define BETWEEN(a, b, c) ((a >= b) && (a <= c))

// Cause a system delay of the given time
void delay(uint32_t ms);
