#include <stdlib.h>
#include "game.h"
#include "../include/SDL.h"
#include "display.h"
#include "connection.h"
#include "tetris.h"
#include "tetris_piece.h"

void init_board() {
    int i, j;
    for (i = 0; i < HEIGHT_BLOCK; i++)
        for (j = 0; j < WIDTH_BLOCK; j++)
            board[i][j] = 0;
}


void change_piece() {
    init_piece();
    next_piece = rand() % 7;
}

void add_piece_in_board() {
    if (piece.x0) board[piece.y][piece.x] = piece.type;
    if (piece.x1) board[piece.y][piece.x + 1] = piece.type;
    if (piece.x2) board[piece.y][piece.x + 2] = piece.type;
    if (piece.x3) board[piece.y][piece.x + 3] = piece.type;
    if (piece.y0) board[piece.y + 1][piece.x] = piece.type;
    if (piece.y1) board[piece.y + 1][piece.x + 1] = piece.type;
    if (piece.y2) board[piece.y + 1][piece.x + 2] = piece.type;
    if (piece.y3) board[piece.y + 1][piece.x + 3] = piece.type;
    if (piece.z0) board[piece.y + 2][piece.x] = piece.type;
    if (piece.z1) board[piece.y + 2][piece.x + 1] = piece.type;
    if (piece.z2) board[piece.y + 2][piece.x + 2] = piece.type;
    if (piece.z3) board[piece.y + 2][piece.x + 3] = piece.type;
    if (piece.r0) board[piece.y + 3][piece.x] = piece.type;
    if (piece.r1) board[piece.y + 3][piece.x + 1] = piece.type;
    if (piece.r2) board[piece.y + 3][piece.x + 2] = piece.type;
    if (piece.r3) board[piece.y + 3][piece.x + 3] = piece.type;
}


void remove_actual_piece_in_board() {
    if (piece.x0) board[piece.y][piece.x] = 0;
    if (piece.x1) board[piece.y][piece.x + 1] = 0;
    if (piece.x2) board[piece.y][piece.x + 2] = 0;
    if (piece.x3) board[piece.y][piece.x + 3] = 0;
    if (piece.y0) board[piece.y + 1][piece.x] = 0;
    if (piece.y1) board[piece.y + 1][piece.x + 1] = 0;
    if (piece.y2) board[piece.y + 1][piece.x + 2] = 0;
    if (piece.y3) board[piece.y + 1][piece.x + 3] = 0;
    if (piece.z0) board[piece.y + 2][piece.x] = 0;
    if (piece.z1) board[piece.y + 2][piece.x + 1] = 0;
    if (piece.z2) board[piece.y + 2][piece.x + 2] = 0;
    if (piece.z3) board[piece.y + 2][piece.x + 3] = 0;
    if (piece.r0) board[piece.y + 3][piece.x] = 0;
    if (piece.r1) board[piece.y + 3][piece.x + 1] = 0;
    if (piece.r2) board[piece.y + 3][piece.x + 2] = 0;
    if (piece.r3) board[piece.y + 3][piece.x + 3] = 0;
}


void verification_gravity() {
    if (piece.y + 3 == HEIGHT_BLOCK ||
        board[piece.y + 4][piece.x] != 0 ||
        board[piece.y + 4][piece.x + 1] != 0 ||
        board[piece.y + 4][piece.x + 2] != 0 ||
        board[piece.y + 4][piece.x + 3] != 0) {
        change_piece();
        piece.y = 0;
        piece.x = 0;
    }
}


void go_back_up_board() {
    int i, j;
    for (i = 0; i < HEIGHT_BLOCK; i++) {
        for (j = 0; j < WIDTH_BLOCK; j++)
            board[i][j] = board[i + 1][j];
    }
}

void go_back_down_board() {
    int i, j;
    for (i = HEIGHT_BLOCK - 1; i > 0; i--) {
        for (j = 0; j < WIDTH_BLOCK; j++)
            board[i][j] = board[i - 1][j];
    }
}

void add_bad_line() {
    if (nb_little_bad_block - nb_little_bad_block_opponent == LIMIT_BLOCK) {
        go_back_up_board();
        int i;
        for (i = 0; i < WIDTH_BLOCK; i++)
            board[HEIGHT_BLOCK - 1][i] = 8;
        nb_line_bad_block++;
        nb_little_bad_block_opponent += LIMIT_BLOCK;
    }
}

void remove_bad_line() {
    if (nb_line_bad_block != 0) {
        int i;
        for (i = 0; i < WIDTH_BLOCK; i++)
            board[0][i] = 0;
        go_back_down_board();
        nb_line_bad_block--;
    } else {
        nb_little_bad_block_opponent += BLOCK_TO_REMOVE;
    }
}

void gravity() {
    verification_gravity();
    if (limit_second == MAX_FPS) {
        remove_actual_piece_in_board();
        piece.y++;
        add_piece_in_board();
        limit_second = 0;
    }
    limit_second++;
}

void break_line() {
    int i, j;
    for (i = 0; i < HEIGHT_BLOCK; i++) {
        int nb_block = 0;
        for (j = 0; j < WIDTH_BLOCK; j++) {
            if (board[i][j] != 0)
                nb_block++;
        }
        if (nb_block == WIDTH_BLOCK) {
            for (j = 0; j < WIDTH_BLOCK; j++)
                board[i][j] = 0;
            remove_bad_line();
            add_block_query();
            nb_little_bad_block_opponent++;
            // back down all line above
            for (j = i; j > 0; j--) {
                for (int k = 0; k < WIDTH_BLOCK; k++)
                    board[j][k] = board[j - 1][k];
            }
        }
    }
}

void set_nb_bad_block() {
    get_block_query(&nb_little_bad_block);
    add_bad_line();
}


void display_board(SDL_Renderer *renderer, SDL_Texture *texture_block[8]) {
    int i, j;
    for (i = 0; i < HEIGHT_BLOCK; i++) {
        for (j = 0; j < WIDTH_BLOCK; j++) {
            if (board[i][j] != 0)
                display_picture(renderer,
                                texture_block[board[i][j] - 1],
                                j * SIZE_BLOCK,
                                i * SIZE_BLOCK,
                                SIZE_BLOCK,
                                SIZE_BLOCK);
        }
    }
}

void game_manager(SDL_Renderer *renderer, SDL_Texture *texture_block[8]) {
    break_line();
    gravity();
    set_nb_bad_block();
    display_board(renderer, texture_block);
}