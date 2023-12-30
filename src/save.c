#include <stdio.h>
#include <stdlib.h>
#include "save.h"
#include "game.h"


void read_save(char *file_name, int board[HEIGHT_BLOCK][WIDTH_BLOCK]) {
    FILE *fptr = fopen(file_name, "r");
    char myString[300];
    fgets(myString, 300, fptr);
    for (int i = 0; i < HEIGHT_BLOCK; i++) {
        for (int j = 0; j < WIDTH_BLOCK; j++) {
            if ((int) myString[i * WIDTH_BLOCK + j] != 0) {
                board[i][j] = myString[i * WIDTH_BLOCK + j] - 48;
            }
        }
    }
}

void save(char *file_name, char *string) {
    FILE *fptr = fopen(file_name, "w");
    fprintf(fptr, "%s", string);
    fclose(fptr);
}