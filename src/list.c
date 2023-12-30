#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

List *initialisation() {
    List *list = malloc(sizeof(*list));
    Element *element = malloc(sizeof(*element));

    element->player_board[0] = '\0';
    element->next = NULL;
    list->premier = element;

    return list;
}

void insertion(List *list, char new_value[HEIGHT_BLOCK * WIDTH_BLOCK + 1]) {
    Element *new = malloc(sizeof(*new));
    strcpy(new->player_board, new_value);
    new->next = list->premier;
    list->premier = new;
}

void deletion(List *list) {
    Element *to_delete = list->premier;
    list->premier = list->premier->next;
    free(to_delete);
}

void display_list(List *list) {
    Element *actual = list->premier;

    while (actual != NULL) {
        printf("%s ", actual->player_board);
        actual = actual->next;
    }
}