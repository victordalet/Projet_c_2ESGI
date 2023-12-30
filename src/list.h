#ifndef LIST_H
#define LIST_H

#include "game.h"


typedef struct Element Element;
struct Element {
    char player_board[HEIGHT_BLOCK * WIDTH_BLOCK + 1];
    Element *next;
};

typedef struct List List;
struct List {
    Element *premier;
};

List *initialisation();

void insertion(List *list, char new_value[HEIGHT_BLOCK * WIDTH_BLOCK + 1]);

void deletion(List *list);

void display_list(List *list);

#endif