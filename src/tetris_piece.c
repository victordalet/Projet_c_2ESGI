#include "tetris.h"
#include <stdbool.h>
#include <stdio.h>

void init_piece(struct piece *piece) {
    piece->x = 0;
    piece->y = 0;
    piece->rotation = 0;
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
            piece->x0 = false;
            piece->x1 = false;
            piece->x2 = true;
            piece->x3 = true;
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

void rotate_piece_horrible_function(struct piece *piece) {
    int temp_x, temp_y;
    printf("piece->rotation = %d\n", piece->rotation);
    switch (piece->rotation) {
        case 0:
            temp_x = piece->x;
            temp_y = piece->y;
            init_piece(piece);
            piece->x = temp_x;
            piece->y = temp_y;
            break;
        case 90 :
            switch (piece->type) {
                case 1:
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
                    piece->z2 = false;
                    piece->z3 = true;
                    piece->r0 = false;
                    piece->r1 = false;
                    piece->r2 = false;
                    piece->r3 = true;
                    break;
                case 2:
                    piece->x0 = false;
                    piece->x1 = true;
                    piece->x2 = true;
                    piece->x3 = true;
                    piece->y0 = false;
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
                case 3:
                    piece->x0 = false;
                    piece->x1 = true;
                    piece->x2 = true;
                    piece->x3 = true;
                    piece->y0 = false;
                    piece->y1 = false;
                    piece->y2 = false;
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
            break;
        case 180:
            switch (piece->type) {
                case 1:
                    temp_x = piece->x;
                    temp_y = piece->y;
                    init_piece(piece);
                    piece->x = temp_x;
                    piece->y = temp_y;
                    break;
                case 5:
                    temp_x = piece->x;
                    temp_y = piece->y;
                    init_piece(piece);
                    piece->x = temp_x;
                    piece->y = temp_y;
                    break;
                case 7:
                    temp_x = piece->x;
                    temp_y = piece->y;
                    init_piece(piece);
                    piece->x = temp_x;
                    piece->y = temp_y;
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
        case 270 :
            switch (piece->type) {
                case 1:
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
                    piece->z2 = false;
                    piece->z3 = true;
                    piece->r0 = false;
                    piece->r1 = false;
                    piece->r2 = false;
                    piece->r3 = true;
                    break;
                case 2:
                    piece->x0 = false;
                    piece->x1 = false;
                    piece->x2 = false;
                    piece->x3 = true;
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
                    piece->x1 = true;
                    piece->x2 = true;
                    piece->x3 = true;
                    piece->y0 = false;
                    piece->y1 = false;
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