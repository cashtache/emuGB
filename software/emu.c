// Standard
#include <stdio.h>
// Graphics
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
// emuGB
#include "emu.h"
#include "cart.h"
#include "cpu.h"

/* Emulator components:
 * Cartridge
 * CPU
 * Address bus
 * PPU (Picture Processing Unit)
 * Timer */

// Local emulator context
static emu_ctx ctx;

emu_ctx *emu_get_ctx(void) {
    return &ctx;
}

void delay(uint32_t ms) {
    SDL_Delay(ms);
}

int emu_run(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: emu <rom_file>\r\n");
        return -1;
    } else if (!cart_load(argv[1])) {
        printf("Failed to load ROM file: %s\r\n", argv[1]);
        return -2;
    }

    printf("Cartridge loaded.\r\n");

    SDL_Init(SDL_INIT_VIDEO);
    printf("SDL initialized.\r\n");
    TTF_Init();
    printf("TTF initialized.\r\n");

    cpu_init();

    ctx.paused = false;
    ctx.running = true;
    ctx.ticks = 0;

    while (ctx.running) {
        if (ctx.paused) {
            delay(10);
            continue;
        }

        if (!cpu_step()) {
            printf("CPU stopped.\r\n");
            return -3;
        }

        ctx.ticks++;
    }

    return 0;
}
