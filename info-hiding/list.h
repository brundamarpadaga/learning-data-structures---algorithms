#ifndef LIST_UTILS_H
#define LIST_UTILS_H

typedef struct list list_t; // custom data type

typedef int bool_t;

// constructor and destructor
list_t* list_create();
void list_delete(list_t*);

// public methods
bool_t list_add_element(struct list*,int);
bool_t list_get_element(struct list*, int*);
void print_list(list_t* list);
size_t get_size(list_t* list);

#endif