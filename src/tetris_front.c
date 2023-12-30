#include "../include/SDL.h"
#include "game.h"
#include "display.h"

void display_grid(SDL_Renderer *renderer) {
    int i;
    for (i = 0; i < HEIGHT_BLOCK; i++) {
        draw(renderer,
             (WINDOW_WIDTH / 2) - (SIZE_BLOCK * (WIDTH_BLOCK / 2)),
             i * SIZE_BLOCK,
             SIZE_BLOCK * WIDTH_BLOCK,
             1,
             62,
             58,
             58,
             60);
    }
    for (i = 0; i <= WIDTH_BLOCK; i++) {
        draw(renderer,
             (WINDOW_WIDTH / 2) - (SIZE_BLOCK * (WIDTH_BLOCK / 2)) + (i * SIZE_BLOCK),
             0,
             1,
             SIZE_BLOCK * HEIGHT_BLOCK,
             62,
             58,
             58,
             60);
    }
}


void display_board(SDL_Renderer *renderer, int block_color[8][3], int board[HEIGHT_BLOCK][WIDTH_BLOCK]) {
    int i, j;
    for (i = 0; i < HEIGHT_BLOCK; i++) {
        for (j = 0; j < WIDTH_BLOCK; j++) {
            if (board[i][j] != 0) {
                draw(renderer,
                     j * SIZE_BLOCK + (WINDOW_WIDTH / 2) - (SIZE_BLOCK * (WIDTH_BLOCK / 2)),
                     i * SIZE_BLOCK,
                     SIZE_BLOCK,
                     SIZE_BLOCK,
                     block_color[board[i][j] - 1][0],
                     block_color[board[i][j] - 1][1],
                     block_color[board[i][j] - 1][2],
                     255);
            }
        }
    }
}

void display_next_piece(SDL_Renderer *renderer, SDL_Texture *texture_piece[7], int next_piece) {
    display_picture(renderer,
                    texture_piece[next_piece - 1],
                    (WINDOW_WIDTH / 2) + (SIZE_BLOCK * (WIDTH_BLOCK / 2)) + 50,
                    50,
                    SIZE_BLOCK,
                    SIZE_BLOCK);
}


void display_bad_piece_on_left_side(SDL_Renderer *renderer, int nb_little_bad_block, int nb_little_bad_block_opponent) {
    int i;
    for (i = 0; i < (nb_little_bad_block - nb_little_bad_block_opponent); i++) {
        draw(renderer,
             (WINDOW_WIDTH / 2) - (SIZE_BLOCK * (WIDTH_BLOCK / 2)) - 50,
             i * SIZE_BLOCK,
             SIZE_BLOCK,
             SIZE_BLOCK,
             122,
             115,
             114,
             255);
    }
}