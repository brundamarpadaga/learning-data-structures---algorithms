#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){


    int array [5]= {64,65,66,67,68};
    printf( " size of array in bytes: %zu \n", sizeof(array));
    printf( " size of array in number of elements: %zu \n", sizeof(array)/sizeof(array[0]));
    memset(array, 255 , sizeof(array));
    for(int i = 0; i < 5; i++){
        printf("%x ", array[i]);
    }
    printf("\n");
    
    char* charArray = (char*) malloc( sizeof(char) * sizeof(array)); // 1byte*20bytes = 20 bytes
    printf( " size of charArray in bytes: %zu \n", sizeof(charArray)); // size of pointer, not the allocated memory
    memmove(charArray,array, sizeof(array));
    for(int i = 0; i < sizeof(array); i++){
        printf("charArray[%d]: %x \n", i , (unsigned char)charArray[i]);// charArray is a pointer, so we use pointer arithmetic to access elements
    }
    printf("\n");
    

    return 0;
}
