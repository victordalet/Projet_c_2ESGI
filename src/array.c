#include "array.h"

#include <stdlib.h>

List *init_array() {
    List *list = malloc(sizeof(*list));
    Element *element = malloc(sizeof(*element));

    element->number = 0;
    element->next = NULL;
    list->premier = element;

    return list;
}

void insert_element_array(List *list, int new_number) {
    Element *new = malloc(sizeof(*new));
    new->number = new_number;
    new->next = list->premier;
    list->premier = new;
}

void remove__element_array(List *list) {
    Element *to_delete = list->premier;
    list->premier = list->premier->next;
    free(to_delete);
}
