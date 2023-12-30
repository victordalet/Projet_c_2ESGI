#ifndef EVENT_H
#define EVENT_H

#include "tetris.h"


void
event_manager(SDL_Event event, bool *run, bool KEYS[323], struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK],
              int *next_piece);

void keyboard_manager(bool KEYS[323], struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece,
                      int *speed_gravity, int user_id, int other_player_board[NB_OTHER_PLAYER_TO_DISPLAY][HEIGHT_BLOCK][WIDTH_BLOCK]);

#endif