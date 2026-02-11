#include <stdio.h>
#include <stdlib.h>

typedef struct array{
    int* data;
    int size;
}array_t;

array_t* createArray( int size ){
    array_t* newArray = (array_t*) malloc(sizeof(array_t));
    newArray->data = (int*) malloc(size * sizeof(int));
    newArray->size = size;
    return newArray;
}

void printArray( array_t* arr){
    for ( int i = 0; i < arr->size; i++){
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}


int main(){

    printf("Creating my own Arrays data structure \n");

    array_t* my_array = createArray(5);
    array_t* my_array2 = createArray(10);
    for ( int i=0; i< my_array->size;i++){
        my_array->data[i] = i;
        my_array2->data[i] = i*2;
        
    }
    printArray(my_array);
    printArray(my_array2);
    printf("my_array2 data at index 5: %d\n", my_array2->data[5]); // this is out of bounds access, but we are just demonstrating pointer arithmetic here
    printf("address: %p\n", my_array2->data + 5); // this is out of bounds access, but we are just demonstrating pointer arithmetic here

    
    free(my_array->data);
    free(my_array);
    free(my_array2->data);
    free(my_array2);
    return 0;

}