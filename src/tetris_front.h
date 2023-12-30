#ifndef TETRIS_FRONT_H
#define TETRIS_FRONT_H

#include "game.h"
#include "../include/SDL.h"

void display_next_piece(SDL_Renderer *renderer, SDL_Texture *texture_piece[7], int next_piece);

void display_board(SDL_Renderer *renderer, int block_color[8][3], int board[HEIGHT_BLOCK][WIDTH_BLOCK]);

void display_grid(SDL_Renderer *renderer);

void display_bad_piece_on_left_side(SDL_Renderer *renderer, int nb_little_bad_block, int nb_little_bad_block_opponent);

#endif