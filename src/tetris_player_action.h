#ifndef TEST_TETRIS_PLAYER_ACTION_H
#define TEST_TETRIS_PLAYER_ACTION_H

#include "tetris.h"


void move_left(struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece, int *speed_gravity, int user_id);

void move_right(struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece, int *speed_gravity, int user_id);

void move_down(struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece, int *speed_gravity, int user_id);

void move_direct_down(struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece, int *speed_gravity, int user_id);

void set_rotation(int delta, struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK]);

#endif