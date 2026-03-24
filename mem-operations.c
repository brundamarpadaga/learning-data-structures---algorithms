#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// This code demonstrates the use of memory manipulation functions in C, such as memset, memmove, and memcpy. It also shows how to calculate the size of an array and how to handle character arrays (strings) in C.

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
    memmove(charArray,array, sizeof(array)); // copy 20 bytes from array to charArray, it may not be null-terminated
    for(int i = 0; i < sizeof(array)-1; i++){
        printf("charArray[%d]: %x \n", i , (unsigned char)charArray[i]);// charArray is a pointer, so we use pointer arithmetic to access elements
    }
    charArray[sizeof(array)-1] = '\0'; // null-terminate the char array
    printf("\n");
    

    memset(charArray, 65 , sizeof(array)-1); // set the allocated memory to 0
    printf("%s\n", charArray); // print charArray as a string, it may not be null-terminated
    char dst[20]; // array of 20 characters
    memset(dst, 0 , sizeof(dst)); // set the allocated memory to 0
    memcpy(dst, charArray, 13); // copy 20 bytes from charArray to dst
    for(int i = 0; i < sizeof(dst); i++){
        printf("dst[%d]: %c \n", i , (unsigned char)dst[i]);
    }
    printf("\n");
    
    printf("dst as string: %s\n", dst); // print dst as a string, it may not be null-terminated


    return 0;
}
