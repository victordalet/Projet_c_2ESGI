#ifndef GAME_MANAGEMENT_H
#define GAME_MANAGEMENT_H

#include "../include/mysql.h"
#include "tetris.h"

void loading_game(int user_id);

void game_manager(SDL_Renderer *renderer, int block_color[8][3], SDL_Texture *texture_piece[7],
                  int board[HEIGHT_BLOCK][WIDTH_BLOCK],
                  int *nb_little_bad_block_opponent,
                  int *nb_line_bad_block,
                  int *next_piece,
                  int *limit_second,
                  int *nb_little_bad_block,
                  struct piece *piece,
                  int *speed_gravity,
                  int user_id,
                  int other_player_board[NB_OTHER_PLAYER_TO_DISPLAY][HEIGHT_BLOCK][WIDTH_BLOCK]);

#endif