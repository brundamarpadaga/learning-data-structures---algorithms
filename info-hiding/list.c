#include<stdlib.h>
#include<stdio.h>
#include "list.h"

#define MAX_SIZE 10

typedef struct list{  // custom data type 
    
    int* array;
    int tail_index;

}  list_t ;






bool_t __list_init(list_t* list){
    list->array = (int*) malloc(sizeof(int) * MAX_SIZE);
    if(list->array == NULL){
        printf("Memory allocation failed for list->array\n");
        return 0;
    }
    list->tail_index = -1;
    return 1;
}

// public methods

// constructor and destructor
list_t* list_create(){
    list_t* list = (list_t*) malloc(sizeof(list_t)); // allocate memory for the list structure
    if(list == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    if(!__list_init(list)){
        free(list);
        return NULL;
    }
    return list;
}

void list_delete(list_t* list){
    free(list->array);
    free(list);
}


// more methods
bool_t list_add_element(struct list* list, int num){
    if(list->tail_index == MAX_SIZE-1){
        printf("ERROR: Cannot add element to the list. List is full!\n");
        return 0;
    }
    ++list->tail_index; // increment the tail index
    printf("Adding %d to the list\n", num);
    printf("Tail index before adding: %d\n", list->tail_index);
    list->array[list->tail_index] = num; // add the element to the array
    return 1;

}
bool_t list_get_element(list_t* list, int* result){
    if(list->tail_index == -1){
        printf("List is empty\n");
        return 0;
    }
    *result = list->array[list->tail_index];
    list->tail_index--;
    return 1;
}

void print_list(list_t* list){
    for(int i = 0; i <= list->tail_index; i++){
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

size_t get_size(list_t* list){
    return (list->tail_index+1);
}


