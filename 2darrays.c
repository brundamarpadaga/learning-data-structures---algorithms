#include <stdio.h>
#include <stdlib.h>


void print2dArrayByPointer( int* arr, int rows, int cols){
    printf("Printing 2D array using pointer arithmetic:\n");
    for(int i = 0; i<rows;i++){
        for(int j =0; j < cols ;j++){
            printf("%d ",arr[i*cols+j]);
        }
        printf("\n");
    }
}

void print2dArrayDynamic( int* arr, int rows, int cols){
    // 2d array is contiguous in memory, so we can use pointer arithmetic to access elements
    printf("Printing dynamic 2D array using pointer arithmetic:\n");
    for(int i = 0; i<rows;i++){
        for(int j =0; j < cols ;j++){
            printf("%d ",arr[i*cols+j]);
        }
        printf("\n");
    }
}

void main(){
    printf("Learning about 2D Arrays in C17! \n");

    int rows = 3;
    int cols = 4;

    int matrix[3][4]; // declaring a 2D array (matrix)

    int *matrix2 = (int*) malloc(rows * cols * sizeof(int)); // creating a dynamic 2D array using a single pointer
    
    
    
    int temp = 0;
    printf("Initializing the 2D array with values from 0 to %d\n", rows*cols-1);
    for ( int i = 0; i < rows; i++){
        for ( int j = 0; j < cols; j++){
            matrix[i][j] = temp++; // initializing the 2D array with some values
            matrix2[i*cols + j] = matrix[i][j]; // initializing the dynamic 2D array using pointer arithmetic
        }
    }



    // printing the 2D array
    printf("2D Array (Matrix):\n");
    for ( int i = 0; i < rows; i++){
        for ( int j = 0; j < cols; j++){
            printf("%d ", matrix[i][j]); // accessing elements of the 2D array
        }
        printf("\n");
    }

    print2dArrayByPointer(&matrix[0][0], rows, cols); // passing 2D array to function using pointer
    print2dArrayDynamic(matrix2, rows, cols); // passing dynamic 2D array to function using pointer
    free(matrix2); // free the dynamically allocated memory
}