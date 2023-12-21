#include <stdio.h>
#include "stdbool.h"
#include "../include/sdl.h"

void event_manager(SDL_Event event, bool *run, bool KEYS[323]) {
    switch (event.type) {
        case SDL_QUIT:
            *run = false;
            break;
        case SDL_KEYDOWN:
            KEYS[event.key.keysym.sym] = true;
            break;
        case SDL_KEYUP:
            KEYS[event.key.keysym.sym] = false;
        case SDL_MOUSEBUTTONDOWN:
            KEYS[323] = true;
            break;
        case SDL_MOUSEBUTTONUP:
            KEYS[323] = false;
            break;
        default:
            break;
    }
}

void keyboard_manager(bool KEYS[323]) {
    if (KEYS[(int) ' '])
        printf("SPACE\n");
    if (!KEYS[323]) {
        KEYS[323] = true;
    }
}