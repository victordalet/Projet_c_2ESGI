#ifndef TETRIS_H
#define TETRIS_H

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

struct piece piece;
int next_piece;
int nb_little_bad_block = 0;
int nb_line_bad_block = 0;
int nb_little_bad_block_opponent = 0;
int limit_second = 0;

int board[HEIGHT_BLOCK][WIDTH_BLOCK];

void init_board();

void init_piece();

void change_piece();

void add_piece_in_board();

void remove_actual_piece_in_board();

void verification_gravity();

void go_back_up_board();

void go_back_down_board();

void add_bad_line();

void remove_bad_line();

void gravity();

void break_line();

void set_nb_bad_block();

void display_board(SDL_Renderer *renderer, SDL_Texture *texture_block[8]);

void game_manager(SDL_Renderer *renderer, SDL_Texture *texture_block[8]);

#endif