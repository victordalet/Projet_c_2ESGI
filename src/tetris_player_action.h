#include "tetris.h"
#include "tetris_piece.h"

void move_left() {
    verification_gravity();
    remove_actual_piece_in_board();
    piece.x--;
    add_piece_in_board();
}

void move_right() {
    verification_gravity();
    remove_actual_piece_in_board();
    piece.x++;
    add_piece_in_board();
}


void set_rotation(int delta) {
    piece.rotation += delta * 90;
    if (piece.rotation == 360 || piece.rotation == -360)
        piece.rotation = 0;
    rotate_piece_horrible_function();
}