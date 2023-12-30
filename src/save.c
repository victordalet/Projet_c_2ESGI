#include <stdio.h>
#include "save.h"
#include "game.h"


void read_file(char *file_name) {
    FILE *fptr = fopen(file_name, "r");
    char c = fgetc(fptr);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
}

void save(char *file_name, char *string) {
    FILE* fptr = fopen(file_name, "w");
    fprintf(fptr, "%s", string);
    fclose(fptr);
}