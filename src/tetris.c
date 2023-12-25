#include <stdlib.h>
#include <stdio.h>

struct piece {
    int x;
    int y;
    int rotation;
    int type;
};

struct piece piece;

int board[20][10];
int next_piece[4][4];

void management_next_piece() {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++)
            next_piece[i][j] = next_piece[i][j + 1];
    }
    for (i = 0; i < 4; i++)
        next_piece[i][3] = rand() % 7;
}

void init_next_piece() {
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            next_piece[i][j] = rand() % 7;
}

void init_board() {
    int i, j;
    for (i = 0; i < 20; i++)
        for (j = 0; j < 10; j++)
            board[i][j] = 0;
}

void init_piece() {
    piece.x = 3;
    piece.y = 0;
    piece.rotation = 0;
    piece.type = next_piece[0][0];
    management_next_piece();
}

void init_game() {
    init_board();
    init_next_piece();
    init_piece();
}

void move_piece(int x, int y) {
    piece.x += x;
    piece.y += y;
}

void rotate_piece() {
    piece.rotation = (piece.rotation + 1) % 4;
}

void management_break_line() {
    int i, j, k;
    int nb_break_line = 0;
    for (i = 0; i < 20; i++) {
        int nb_block = 0;
        for (j = 0; j < 10; j++) {
            if (board[i][j] != 0)
                nb_block++;
        }
        if (nb_block == 10) {
            nb_break_line++;
            for (k = i; k > 0; k--) {
                for (j = 0; j < 10; j++) {
                    board[k][j] = board[k - 1][j];
                }
            }
        }
    }
}

void display_board() {
    int i, j;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 10; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}