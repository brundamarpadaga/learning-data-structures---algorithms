#include<stdio.h>
#include "list.h"



int main(){

    list_t *myList = list_create();

    list_add_element(myList, 1);
    list_add_element(myList, 2);
    list_add_element(myList, 3);
    list_add_element(myList, 4);
    list_add_element(myList, 5);
    list_add_element(myList, 6);
    list_add_element(myList, 7);
    list_add_element(myList, 8);
    list_add_element(myList, 9);
    list_add_element(myList, 9);
    list_add_element(myList, 10);

    

    print_list(myList);
    int result;
    list_get_element(myList, &result);
    printf("Result: %d\n", result);
    list_get_element(myList, &result);
    printf("Result: %d\n", result);

    list_t* reversedList = list_create();
    
    for(int i = get_size(myList); i >= 0; i--){
        list_get_element(myList, &result);
        list_add_element(reversedList, result);

    }

    print_list(reversedList);

    list_delete(myList);
    return 0;
}