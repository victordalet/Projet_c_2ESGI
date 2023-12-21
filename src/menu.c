#include "sdl.h"
#include "stdbool.h"
#include "game.h"


void
launch_level(bool *in_level, bool KEYS[323]) {
    if (!*in_level) {
        int x, y, max_height, max_width, min_height, min_width;
        SDL_GetMouseState(&x, &y);
        for (int i = 0; i < NUMBER_ICON_MENU; i++) {
            min_width = 20 + WINDOW_WIDTH / (NUMBER_ICON_MENU + 1) * i;
            min_height = WINDOW_HEIGHT / 2 - 100;
            max_width = 20 + WINDOW_WIDTH / (NUMBER_ICON_MENU + 1) * (i + 1);
            max_height = WINDOW_HEIGHT / 2 + 100;
            if (!KEYS[323]) {
                if ((x > min_width && x < max_width) && (y > min_height && y < max_height)) {
                    *in_level = true;
                }
            }
        }
    }
}
