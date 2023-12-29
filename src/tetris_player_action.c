#include "tetris.h"
#include "game.h"
#include "tetris_piece.h"

void move_left(struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece) {
    verification_gravity(piece, board, next_piece);
    remove_actual_piece_in_board(*piece, board);
    piece->x -= 1;
    add_piece_in_board(*piece, board);
}

void move_right(struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece) {
    verification_gravity(piece, board, next_piece);
    remove_actual_piece_in_board(*piece, board);
    piece->x += 1;
    add_piece_in_board(*piece, board);
}

void move_down(struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece) {
    verification_gravity(piece, board, next_piece);
    remove_actual_piece_in_board(*piece, board);
    piece->y += 1;
    add_piece_in_board(*piece, board);
}

void move_direct_down(struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece) {
    while (piece->y + 3 != HEIGHT_BLOCK &&
           board[piece->y + 4][piece->x] == 0 &&
           board[piece->y + 4][piece->x + 1] == 0 &&
           board[piece->y + 4][piece->x + 2] == 0 &&
           board[piece->y + 4][piece->x + 3] == 0)
        move_down(piece, board, next_piece);
}


void set_rotation(int delta, struct piece *piece, int next_piece) {
    piece->rotation += delta * 90;
    if (piece->rotation == 360 || piece->rotation == -360)
        piece->rotation = 0;
    rotate_piece_horrible_function(piece, next_piece);
}