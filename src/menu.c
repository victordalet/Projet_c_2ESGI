#include "sdl.h"
#include "stdbool.h"
#include "game.h"
#include "game-management.h"
#include "../include/mysql.h"
#include "tetris.h"


void
launch_level(bool *in_level, bool KEYS[323], int user_id, int board[HEIGHT_BLOCK][WIDTH_BLOCK]) {
    if (!*in_level) {
        int x, y;
        int image_size = 100;
        int max_height = WINDOW_HEIGHT / 2 + image_size;
        int min_height = WINDOW_HEIGHT / 2 - image_size;
        int min_width = WINDOW_WIDTH / 2 - image_size;
        int max_width = WINDOW_WIDTH / 2 + image_size;
        SDL_GetMouseState(&x, &y);
        if (!KEYS[323]) {
            if ((x > min_width && x < max_width) && (y > min_height && y < max_height)) {
                loading_game(user_id);
                *in_level = true;
                init_board(board);
            }
        }
    }
}
