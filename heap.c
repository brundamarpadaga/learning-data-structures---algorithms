#include <stdio.h>
#include <stdlib.h>


int* fun(){
    int* ptr = (int*) malloc ( sizeof(int) ); // memory allocated on heap
     
    int a = 10; // local variable on stack
    int* ptr2 = (int*) malloc ( sizeof(int) ); // another heap allocation
    *ptr = 42;
    ptr2 = &a; // DO NOT DO THIS ptr2 now points to stack variable (not heap) heap memory is leaked here
    printf("Value at ptr: %d\n", *ptr);
    printf("Value at ptr2: %d\n", *ptr2);
    //free(ptr); // manually freeing the memory
    return ptr; // returning pointer to heap memory
}

int* fun3(){
    int localVar = 10; // local variable on stack
    int* heapVar = (int*) malloc ( sizeof(int) ); // heap variable
    *heapVar = localVar * 2; // updating heap variable
    return heapVar; // safe to return heap memory but not stack memory localVar
}

int* fun4(){
    int* array = (int*) malloc ( 10 * sizeof(int) ); // heap allocated array
    for(int i = 0; i < 10; i++){
        array[i] = i * i;
    }
    return array;
}

int main(){
    printf("Learning about Heaps! \n");
    int *localArray = fun4(); // localArray is a pointer to heap memory
    int* heapVar1 = fun3();
    int* heapVar = fun(); // I can access heap memory even after fun() ends,
    // scope of ptr is gone but memory remains valid
    printf("Value from heap in main: %d\n", *heapVar);
    for(int i = 0; i < 10; i++){
        printf("Array element %d: %d\n", i, localArray[i]);
    }

    printf("Value from fun3 heap memory: %d\n", *heapVar1);
    free(heapVar1); // free when done
    free(heapVar); // free when done
    free(localArray); // free when done
    return 0;
}