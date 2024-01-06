#include <stdbool.h>
#include <mysql/mysql.h>

#ifndef MENU_H
#define MENU_H

void
launch_level(bool *in_level, bool KEYS[323], int user_id, int board[HEIGHT_BLOCK][WIDTH_BLOCK], struct piece *piece,
             int *next_piece, SDL_Texture *loading_texture, SDL_Renderer *renderer, bool *in_stat);

#endif