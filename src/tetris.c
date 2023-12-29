#include <stdlib.h>
#include "game.h"
#include "../include/SDL.h"
#include "display.h"
#include "connection.h"
#include "tetris.h"
#include "tetris_piece.h"

void init_board(int board[HEIGHT_BLOCK][WIDTH_BLOCK]) {
    int i, j;
    for (i = 0; i < HEIGHT_BLOCK; i++)
        for (j = 0; j < WIDTH_BLOCK; j++)
            board[i][j] = 0;
}


void change_piece(struct piece *piece, int *next_piece) {
    init_piece(piece, *next_piece);
    *next_piece = rand() % 7;
}

void add_piece_in_board(struct piece piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK]) {
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


void remove_actual_piece_in_board(struct piece piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK]) {
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


void verification_gravity(struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece) {
    if (piece->y + 3 == HEIGHT_BLOCK ||
        board[piece->y + 4][piece->x] != 0 ||
        board[piece->y + 4][piece->x + 1] != 0 ||
        board[piece->y + 4][piece->x + 2] != 0 ||
        board[piece->y + 4][piece->x + 3] != 0) {
        change_piece(piece, next_piece);
        piece->y = 0;
        piece->x = 0;
    }
}


void go_back_up_board(int board[HEIGHT_BLOCK][WIDTH_BLOCK]) {
    int i, j;
    for (i = 0; i < HEIGHT_BLOCK; i++) {
        for (j = 0; j < WIDTH_BLOCK; j++)
            board[i][j] = board[i + 1][j];
    }
}

void go_back_down_board(int board[HEIGHT_BLOCK][WIDTH_BLOCK]) {
    int i, j;
    for (i = HEIGHT_BLOCK - 1; i > 0; i--) {
        for (j = 0; j < WIDTH_BLOCK; j++)
            board[i][j] = board[i - 1][j];
    }
}

void add_bad_line(int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *nb_little_bad_block_opponent, int *nb_line_bad_block, int nb_little_bad_block) {
    if (nb_little_bad_block - *nb_little_bad_block_opponent == LIMIT_BLOCK) {
        go_back_up_board(board);
        int i;
        for (i = 0; i < WIDTH_BLOCK; i++)
            board[HEIGHT_BLOCK - 1][i] = 8;
        *nb_line_bad_block += 1;
        *nb_little_bad_block_opponent += LIMIT_BLOCK;
    }
}

void remove_bad_line(int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *nb_little_bad_block_opponent, int *nb_line_bad_block) {
    if (*nb_line_bad_block != 0) {
        int i;
        for (i = 0; i < WIDTH_BLOCK; i++)
            board[0][i] = 0;
        go_back_down_board(board);
        *nb_line_bad_block -= 1;
    } else {
        *nb_little_bad_block_opponent += BLOCK_TO_REMOVE;
    }
}

void gravity(int *limit_second, struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece) {
    verification_gravity(piece, board, next_piece);
    if (*limit_second == MAX_FPS) {
        remove_actual_piece_in_board(*piece, board);
        piece->y++;
        add_piece_in_board(*piece, board);
        *limit_second = 0;
    }
    *limit_second += 1;
}

void break_line(int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *nb_little_bad_block_opponent,int *nb_line_bad_block) {
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
            remove_bad_line(board, nb_little_bad_block_opponent, nb_line_bad_block);
            add_block_query();
            *nb_little_bad_block_opponent += 1;
            // back down all line above
            for (j = i; j > 0; j--) {
                for (int k = 0; k < WIDTH_BLOCK; k++)
                    board[j][k] = board[j - 1][k];
            }
        }
    }
}

void are_you_lost(bool *in_level, int user_id, int board[HEIGHT_BLOCK][WIDTH_BLOCK]) {
    int i;
    for (i = 0; i < WIDTH_BLOCK; i++) {
        if (board[0][i] != 0) {
            *in_level = false;
            exit_game_during_game_query(user_id);
        }
    }
}

void set_nb_bad_block(int board[HEIGHT_BLOCK][WIDTH_BLOCK],int * nb_little_bad_block, int *nb_little_bad_block_opponent, int *nb_line_bad_block) {
    get_block_query(nb_little_bad_block);
    add_bad_line(board, nb_little_bad_block_opponent, nb_line_bad_block, *nb_little_bad_block);
}


void display_board(SDL_Renderer *renderer, int block_color[8][3], int board[HEIGHT_BLOCK][WIDTH_BLOCK]) {
    int i, j;
    for (i = 0; i < HEIGHT_BLOCK; i++) {
        for (j = 0; j < WIDTH_BLOCK; j++) {
            if (board[i][j] != 0)
                draw(renderer,
                     j * SIZE_BLOCK,
                     i * SIZE_BLOCK,
                     SIZE_BLOCK,
                     SIZE_BLOCK,
                     block_color[board[i][j] - 1][0],
                     block_color[board[i][j] - 1][1],
                     block_color[board[i][j] - 1][2]);
        }
    }
}

void display_next_piece(SDL_Renderer *renderer, SDL_Texture *texture_piece[7], int next_piece) {
    display_picture(renderer,
                    texture_piece[next_piece],
                    WIDTH_BLOCK * SIZE_BLOCK + 50,
                    0,
                    SIZE_BLOCK * 4,
                    SIZE_BLOCK * 4);
}
