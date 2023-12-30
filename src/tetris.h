#ifndef TETRIS_H
#define TETRIS_H

#include <stdbool.h>
#include "game.h"

struct piece {
    int x;
    int y;
    int rotation;
    int type;
    bool x0;
    bool x1;
    bool x2;
    bool x3;
    bool y0;
    bool y1;
    bool y2;
    bool y3;
    bool z0;
    bool z1;
    bool z2;
    bool z3;
    bool r0;
    bool r1;
    bool r2;
    bool r3;
};


void init_board(int board[HEIGHT_BLOCK][WIDTH_BLOCK]);

void change_piece(struct piece *piece, int *next_piece);

void add_piece_in_board(struct piece piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK]);

void remove_actual_piece_in_board(struct piece piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK]);

void verification_gravity(struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece, int *speed_gravity, int user_id);

void go_back_up_board(int board[HEIGHT_BLOCK][WIDTH_BLOCK]);

void go_back_down_board(int board[HEIGHT_BLOCK][WIDTH_BLOCK]);

void add_bad_line(int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *nb_little_bad_block_opponent, int *nb_line_bad_block, int nb_little_bad_block);

void remove_bad_line(int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *nb_little_bad_block_opponent, int *nb_line_bad_block);

void gravity(int *limit_second, struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece, int *speed_gravity,int user_id);

void break_line(int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *nb_little_bad_block_opponent, int *nb_line_bad_block);

void set_nb_bad_block(int board[HEIGHT_BLOCK][WIDTH_BLOCK],int * nb_little_bad_block, int *nb_little_bad_block_opponent, int *nb_line_bad_block);

void are_you_lost(bool *in_level, int user_id, int board[HEIGHT_BLOCK][WIDTH_BLOCK]);


#endif