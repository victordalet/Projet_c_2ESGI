#include "tetris.h"
#include <stdbool.h>

void init_piece(struct piece *piece, int next_piece) {
    piece->x = 0;
    piece->y = 0;
    piece->rotation = 0;
    piece->type = next_piece;
    switch (piece->type) {
        case 1: // white blue
            piece->x0 = true;
            piece->x1 = true;
            piece->x2 = true;
            piece->x3 = true;
            piece->y0 = false;
            piece->y1 = false;
            piece->y2 = false;
            piece->y3 = false;
            piece->z0 = false;
            piece->z1 = false;
            piece->z2 = false;
            piece->z3 = false;
            piece->r0 = false;
            piece->r1 = false;
            piece->r2 = false;
            piece->r3 = false;
            break;
        case 2: // blue
            piece->x0 = false;
            piece->x1 = false;
            piece->x2 = true;
            piece->x3 = true;
            piece->y0 = false;
            piece->y1 = false;
            piece->y2 = false;
            piece->y3 = true;
            piece->z0 = false;
            piece->z1 = false;
            piece->z2 = false;
            piece->z3 = true;
            piece->r0 = false;
            piece->r1 = false;
            piece->r2 = false;
            piece->r3 = false;
            break;
        case 3: // orange
            piece->x0 = false;
            piece->x1 = false;
            piece->x2 = false;
            piece->x3 = true;
            piece->y0 = false;
            piece->y1 = false;
            piece->y2 = false;
            piece->y3 = true;
            piece->z0 = false;
            piece->z1 = false;
            piece->z2 = true;
            piece->z3 = true;
            piece->r0 = false;
            piece->r1 = false;
            piece->r2 = false;
            piece->r3 = false;
            break;
        case 4: // yellow
            piece->x0 = true;
            piece->x1 = true;
            piece->x2 = false;
            piece->x3 = false;
            piece->y0 = true;
            piece->y1 = true;
            piece->y2 = false;
            piece->y3 = false;
            piece->z0 = false;
            piece->z1 = false;
            piece->z2 = false;
            piece->z3 = false;
            piece->r0 = false;
            piece->r1 = false;
            piece->r2 = false;
            piece->r3 = false;
            break;
        case 5: // green
            piece->x0 = false;
            piece->x1 = false;
            piece->x2 = false;
            piece->x3 = true;
            piece->y0 = false;
            piece->y1 = false;
            piece->y2 = true;
            piece->y3 = true;
            piece->z0 = false;
            piece->z1 = false;
            piece->z2 = true;
            piece->z3 = false;
            piece->r0 = false;
            piece->r1 = false;
            piece->r2 = false;
            piece->r3 = false;
            break;
        case 6: // purple
            piece->x0 = false;
            piece->x1 = false;
            piece->x2 = false;
            piece->x3 = true;
            piece->y0 = false;
            piece->y1 = false;
            piece->y2 = true;
            piece->y3 = true;
            piece->z0 = false;
            piece->z1 = false;
            piece->z2 = false;
            piece->z3 = true;
            piece->r0 = false;
            piece->r1 = false;
            piece->r2 = false;
            piece->r3 = false;
            break;
        case 7: // red
            piece->x0 = false;
            piece->x1 = false;
            piece->x2 = true;
            piece->x3 = false;
            piece->y0 = false;
            piece->y1 = false;
            piece->y2 = true;
            piece->y3 = true;
            piece->z0 = false;
            piece->z1 = false;
            piece->z2 = false;
            piece->z3 = true;
            piece->r0 = false;
            piece->r1 = false;
            piece->r2 = false;
            piece->r3 = false;
            break;
    }
}

void rotate_piece_horrible_function(struct piece *piece, int next_piece) {
    int temp_x, temp_y, temp_type;
    switch (piece->rotation) {
        case 0:
            temp_x = piece->x;
            temp_y = piece->y;
            temp_type = piece->type;
            init_piece(piece, next_piece);
            piece->x = temp_x;
            piece->y = temp_y;
            piece->type = temp_type;
            break;
        case 90 | -270:
            switch (piece->type) {
                case 1:
                    piece->x0 = false;
                    piece->x1 = true;
                    piece->x2 = false;
                    piece->x3 = false;
                    piece->y0 = false;
                    piece->y1 = true;
                    piece->y2 = false;
                    piece->y3 = false;
                    piece->z0 = false;
                    piece->z1 = true;
                    piece->z2 = false;
                    piece->z3 = false;
                    piece->r0 = false;
                    piece->r1 = true;
                    piece->r2 = false;
                    piece->r3 = false;
                    break;
                case 2:
                    piece->x0 = false;
                    piece->x1 = false;
                    piece->x2 = false;
                    piece->x3 = false;
                    piece->y0 = false;
                    piece->y1 = true;
                    piece->y2 = true;
                    piece->y3 = true;
                    piece->z0 = false;
                    piece->z1 = true;
                    piece->z2 = false;
                    piece->z3 = false;
                    piece->r0 = false;
                    piece->r1 = false;
                    piece->r2 = false;
                    piece->r3 = false;
                    break;
                case 3:
                    piece->x0 = false;
                    piece->x1 = false;
                    piece->x2 = true;
                    piece->x3 = true;
                    piece->y0 = false;
                    piece->y1 = false;
                    piece->y2 = true;
                    piece->y3 = false;
                    piece->z0 = false;
                    piece->z1 = false;
                    piece->z2 = true;
                    piece->z3 = false;
                    piece->r0 = false;
                    piece->r1 = false;
                    piece->r2 = false;
                    piece->r3 = false;
                    break;
                case 5:
                    piece->x0 = false;
                    piece->x1 = true;
                    piece->x2 = true;
                    piece->x3 = false;
                    piece->y0 = false;
                    piece->y1 = false;
                    piece->y2 = true;
                    piece->y3 = true;
                    piece->z0 = false;
                    piece->z1 = false;
                    piece->z2 = false;
                    piece->z3 = false;
                    piece->r0 = false;
                    piece->r1 = false;
                    piece->r2 = false;
                    piece->r3 = false;
                    break;
                case 6:
                    piece->x0 = false;
                    piece->x1 = false;
                    piece->x2 = false;
                    piece->x3 = false;
                    piece->y0 = false;
                    piece->y1 = true;
                    piece->y2 = true;
                    piece->y3 = true;
                    piece->z0 = false;
                    piece->z1 = false;
                    piece->z2 = false;
                    piece->z3 = false;
                    piece->r0 = false;
                    piece->r1 = false;
                    piece->r2 = false;
                    piece->r3 = false;
                    break;
                case 7:
                    piece->x0 = false;
                    piece->x1 = false;
                    piece->x2 = true;
                    piece->x3 = true;
                    piece->y0 = false;
                    piece->y1 = true;
                    piece->y2 = true;
                    piece->y3 = false;
                    piece->z0 = false;
                    piece->z1 = false;
                    piece->z2 = false;
                    piece->z3 = false;
                    piece->r0 = false;
                    piece->r1 = false;
                    piece->r2 = false;
                    piece->r3 = false;
                    break;
            }
            break;
        case 180 | -90:
            switch (piece->type) {
                case 1 | 5 | 7:
                    temp_x = piece->x;
                    temp_y = piece->y;
                    temp_type = piece->type;
                    init_piece(piece, next_piece);
                    piece->x = temp_x;
                    piece->y = temp_y;
                    piece->type = temp_type;
                    break;
                case 2:
                    piece->x0 = false;
                    piece->x1 = false;
                    piece->x2 = true;
                    piece->x3 = false;
                    piece->y0 = false;
                    piece->y1 = false;
                    piece->y2 = true;
                    piece->y3 = false;
                    piece->z0 = false;
                    piece->z1 = false;
                    piece->z2 = true;
                    piece->z3 = true;
                    piece->r0 = false;
                    piece->r1 = false;
                    piece->r2 = false;
                    piece->r3 = false;
                    break;
                case 3:
                    piece->x0 = false;
                    piece->x1 = true;
                    piece->x2 = false;
                    piece->x3 = false;
                    piece->y0 = false;
                    piece->y1 = true;
                    piece->y2 = true;
                    piece->y3 = true;
                    piece->z0 = false;
                    piece->z1 = false;
                    piece->z2 = false;
                    piece->z3 = false;
                    piece->r0 = false;
                    piece->r1 = false;
                    piece->r2 = false;
                    piece->r3 = false;
                    break;
                case 6:
                    piece->x0 = false;
                    piece->x1 = false;
                    piece->x2 = true;
                    piece->x3 = false;
                    piece->y0 = false;
                    piece->y1 = false;
                    piece->y2 = true;
                    piece->y3 = true;
                    piece->z0 = false;
                    piece->z1 = false;
                    piece->z2 = true;
                    piece->z3 = false;
                    piece->r0 = false;
                    piece->r1 = false;
                    piece->r2 = false;
                    piece->r3 = false;
                    break;
            }
        case 270 | -270:
            switch (piece->type) {
                case 1:
                    piece->x0 = false;
                    piece->x1 = true;
                    piece->x2 = false;
                    piece->x3 = false;
                    piece->y0 = false;
                    piece->y1 = true;
                    piece->y2 = false;
                    piece->y3 = false;
                    piece->z0 = false;
                    piece->z1 = true;
                    piece->z2 = false;
                    piece->z3 = false;
                    piece->r0 = false;
                    piece->r1 = true;
                    piece->r2 = false;
                    piece->r3 = false;
                    break;
                case 2:
                    piece->x0 = false;
                    piece->x1 = false;
                    piece->x2 = false;
                    piece->x3 = true;
                    piece->y0 = false;
                    piece->y1 = false;
                    piece->y2 = false;
                    piece->y3 = true;
                    piece->z0 = false;
                    piece->z1 = false;
                    piece->z2 = true;
                    piece->z3 = true;
                    piece->r0 = false;
                    piece->r1 = false;
                    piece->r2 = false;
                    piece->r3 = false;
                    break;
                case 3:
                    piece->x0 = false;
                    piece->x1 = false;
                    piece->x2 = false;
                    piece->x3 = true;
                    piece->y0 = false;
                    piece->y1 = false;
                    piece->y2 = false;
                    piece->y3 = true;
                    piece->z0 = false;
                    piece->z1 = false;
                    piece->z2 = true;
                    piece->z3 = true;
                    piece->r0 = false;
                    piece->r1 = false;
                    piece->r2 = false;
                    piece->r3 = false;
                    break;
                case 5:
                    piece->x0 = false;
                    piece->x1 = true;
                    piece->x2 = true;
                    piece->x3 = false;
                    piece->y0 = false;
                    piece->y1 = false;
                    piece->y2 = true;
                    piece->y3 = true;
                    piece->z0 = false;
                    piece->z1 = false;
                    piece->z2 = false;
                    piece->z3 = false;
                    piece->r0 = false;
                    piece->r1 = false;
                    piece->r2 = false;
                    piece->r3 = false;
                    break;
                case 6:
                    piece->x0 = false;
                    piece->x1 = false;
                    piece->x2 = true;
                    piece->x3 = false;
                    piece->y0 = false;
                    piece->y1 = true;
                    piece->y2 = true;
                    piece->y3 = true;
                    piece->z0 = false;
                    piece->z1 = false;
                    piece->z2 = false;
                    piece->z3 = false;
                    piece->r0 = false;
                    piece->r1 = false;
                    piece->r2 = false;
                    piece->r3 = false;
                    break;
                case 7:
                    piece->x0 = false;
                    piece->x1 = false;
                    piece->x2 = true;
                    piece->x3 = true;
                    piece->y0 = false;
                    piece->y1 = true;
                    piece->y2 = true;
                    piece->y3 = false;
                    piece->z0 = false;
                    piece->z1 = false;
                    piece->z2 = false;
                    piece->z3 = false;
                    piece->r0 = false;
                    piece->r1 = false;
                    piece->r2 = false;
                    piece->r3 = false;
                    break;
            }
    }
}