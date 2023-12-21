#pragma once

// emuGB
#include "common.h"

// The context of the emulator
typedef struct {
    bool paused;
    bool running;
    uint64_t ticks;
} emu_ctx;

// Starts the emulator
int emu_run(int argc, char **argv);
// Gets the current context of the emulator
emu_ctx *emu_get_ctx(void);
