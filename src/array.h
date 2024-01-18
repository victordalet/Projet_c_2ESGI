#ifndef ARRAY_H
#define ARRAY_H

typedef struct Element Element;

struct Element {
    int number;
    Element *next;
};

typedef struct List List;

struct List {
    Element *premier;
};

List *init_array();

void insert_element_array(List *list, int new_number);

void remove__element_array(List *list);

#endif
