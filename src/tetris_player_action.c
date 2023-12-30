#include "tetris.h"
#include "game.h"
#include "tetris_piece.h"


void move_left(struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece, int *speed_gravity, int user_id,int other_player_board[NB_OTHER_PLAYER_TO_DISPLAY][HEIGHT_BLOCK][WIDTH_BLOCK]) {
    if (piece->x == 0)
        return;
    verification_gravity(piece, board, next_piece, speed_gravity,user_id,other_player_board);
    remove_actual_piece_in_board(*piece, board);
    piece->x -= 1;
    add_piece_in_board(*piece, board);
}

void move_right(struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece, int *speed_gravity, int user_id,int other_player_board[NB_OTHER_PLAYER_TO_DISPLAY][HEIGHT_BLOCK][WIDTH_BLOCK]) {
    if ((piece->x + 4 == WIDTH_BLOCK && (piece->r0 || piece->r1 || piece->r2 || piece->r3)) ||
        (piece->x + 3 == WIDTH_BLOCK && (piece->z0 || piece->z1 || piece->z2 || piece->z3)) ||
        (piece->x + 2 == WIDTH_BLOCK && (piece->y0 || piece->y1 || piece->y2 || piece->y3)) ||
        (piece->x + 1 == WIDTH_BLOCK && (piece->x0 || piece->x1 || piece->x2 || piece->x3)))
        return;
    verification_gravity(piece, board, next_piece, speed_gravity,user_id,other_player_board);
    remove_actual_piece_in_board(*piece, board);
    piece->x += 1;
    add_piece_in_board(*piece, board);

}

void move_down(struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece, int *speed_gravity, int user_id,int other_player_board[NB_OTHER_PLAYER_TO_DISPLAY][HEIGHT_BLOCK][WIDTH_BLOCK]) {
    verification_gravity(piece, board, next_piece, speed_gravity,user_id,other_player_board);
    remove_actual_piece_in_board(*piece, board);
    piece->y += 1;
    add_piece_in_board(*piece, board);
}

void move_direct_down(struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece, int *speed_gravity, int user_id,int other_player_board[NB_OTHER_PLAYER_TO_DISPLAY][HEIGHT_BLOCK][WIDTH_BLOCK]) {
    while (piece->y + 3 != HEIGHT_BLOCK &&
           board[piece->y + 4][piece->x] == 0 &&
           board[piece->y + 4][piece->x + 1] == 0 &&
           board[piece->y + 4][piece->x + 2] == 0 &&
           board[piece->y + 4][piece->x + 3] == 0)
        move_down(piece, board, next_piece, speed_gravity,user_id,other_player_board);
}


void set_rotation(int delta, struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK]) {
    piece->rotation += delta * 90;
    if (piece->rotation == 360 || piece->rotation == -360)
        piece->rotation = 0;
    remove_actual_piece_in_board(*piece, board);
    rotate_piece_horrible_function(piece);
    add_piece_in_board(*piece, board);
}