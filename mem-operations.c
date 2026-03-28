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
    char src[20] ;
    for (int i = 0; i < sizeof(src)-1; i++){
        src[i] = 65 + i; // fill src with characters from 'A' to 'T'
    }
    src[sizeof(src)-1] = '\0'; // null-terminate the string
    printf("src: %s\n", src); // print src as a string, it may not be null-terminated
    char dst[20]; // array of 20 characters
    memset(dst, 0 , sizeof(dst)); // set the allocated memory to 0
    memcpy(dst, charArray, 13); // copy 13 bytes from charArray to dst
    memset(dst+13, 66 , 6); // set the remaining bytes to 66
    //dst[19] = '\0'; // null-terminate the string
    
    
    printf("dst as string: %s\n", dst); // print dst as a string, it may not be null-terminated

    memcpy(dst+15, src, 15); // copy 20 bytes from src to dst, src overlaps with dst, it may not be null-terminated
    printf("dst after memcpy from src without null-termination: %s\n", dst); // print dst as a string, it may not be null-terminated
    free(charArray); // free the allocated memory for charArray
    return 0; 
}
