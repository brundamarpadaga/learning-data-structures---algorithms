#include<stdio.h>
#include<stdlib.h>

typedef struct array{

    struct array* self;

    size_t size;
    int* data;

    int (*pfnGet) (struct array*, int);// get data at index
    void (*pfnSet)(struct array*, int, int); // set data at index with a value 
}array_t;


int Get( array_t* array1, int index);
void Set( array_t* array1, int index, int value);

void delete(array_t* array){
    free(array->data);
    free(array->self);
}

void Set( array_t* array1, int index, int value){
    if( index >= 0 && index < array1->size ){
        array1->data[index] = value;
    }
}

int Get( array_t* array1, int index){
    if( index < array1->size && index >= 0 ){
        return array1->data[index];
    }
    return -1; 
}

array_t* newArray(size_t size){
    array_t* newArray = (array_t*)malloc(sizeof(array_t));
    newArray->size = size;
    newArray -> data = (int*)malloc ( size*sizeof(int));
    newArray->pfnGet = Get;
    newArray->pfnSet = Set; 
    return newArray;

}

int main(int argc, char* argv){

    array_t* a1 = newArray(10);
    for(int i = 0; i<a1->size;i++){
        a1->pfnSet(a1,i,i);
    }
    for(int i = 0; i<a1->size;i++){
        printf("%d ",a1->pfnGet(a1,i));
    }
    
}