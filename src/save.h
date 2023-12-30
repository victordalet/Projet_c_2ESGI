#ifndef SAVE_H
#define SAVE_H

#include "game.h"

void read_save(char *file_name, int board[HEIGHT_BLOCK][WIDTH_BLOCK]);

void save(char *file_name, char *string);

#endif
