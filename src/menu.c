#include <SDL2/SDL.h>
#include "stdbool.h"
#include "game.h"
#include "game-management.h"
#include <mysql/mysql.h>
#include "tetris.h"
#include "display.h"


void
launch_level(bool *in_level, bool KEYS[323], int user_id, int board[HEIGHT_BLOCK][WIDTH_BLOCK], struct piece *piece,
             int *next_piece, SDL_Texture *loading_texture, SDL_Renderer *renderer, bool *in_stat) {
    if (!*in_level) {
        int x, y;
        int image_size = 100;
        int max_height = WINDOW_HEIGHT / 2 + image_size;
        int min_height = WINDOW_HEIGHT / 2 - image_size;
        int min_width = WINDOW_WIDTH / 2 - image_size;
        int max_width = WINDOW_WIDTH / 2 + image_size;
        SDL_GetMouseState(&x, &y);
        if (!KEYS[323]) {
            if ((x > min_width && x < max_width) && (y > min_height && y < max_height) && !*in_stat) {
                *in_level = true;
                init_board(board);
                change_piece(piece, next_piece);
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderClear(renderer);
                display_picture(renderer, loading_texture, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
                SDL_RenderPresent(renderer);
                loading_game(user_id);
            }
            if ((x > 50 && x < 150) && (y > WINDOW_HEIGHT - 150 && y < WINDOW_HEIGHT - 50))
                *in_stat = true;
            if ((x > 20 && x < 70) && (y > 20 && y < 70))
                *in_stat = false;
        }
    }
}
