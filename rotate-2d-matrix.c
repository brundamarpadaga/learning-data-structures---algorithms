#include<stdio.h>
#include<stdlib.h>

// rotates a 2D matrix by 90 degrees clockwise in place

void rotate(int** matrix, int matrixSize, int* matrixColSize);
void transpose(int** matrix, int matrixSize, int* matrixColSize);
void reverse(int** matrix, int matrixSize, int* matrixColSize);


int main(){
    int **matrix ;
    int matrixSize = 3;
    int colSize = 3;
    int *matrixColSize = &colSize;
    matrix = (int**) malloc(matrixSize * sizeof(int*)); // allocate memory for 3 rows

    for (int i = 0; i < matrixSize; i++){
        matrix[i] = (int*) malloc(*matrixColSize * sizeof(int)); // allocate memory for 3 columns in each row
    }

    for (int i = 0; i < matrixSize; i++){
        for(int j = 0; j < *matrixColSize; j++){
           matrix[i][j] =  i * (*matrixColSize) + j + 1;
        }
        
    }

    printf("Original Matrix:\n");

    for (int i = 0; i < matrixSize; i++){
        for(int j = 0; j < *matrixColSize; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Rotated Matrix:\n");

    rotate(matrix,matrixSize, matrixColSize);

    for (int i = 0; i < matrixSize; i++){
        for(int j = 0; j < *matrixColSize; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // free the memory
    for (int i = 0; i < matrixSize; i++){
        free(matrix[i]); // free each row
    }
    free(matrix); // free the array of pointers
    return 0;

}

void transpose(int** matrix, int matrixSize, int* matrixColSize){

    for (int i = 0; i < matrixSize   ; i++){
        for( int j = i; j < (*matrixColSize); j++){
            int temp = matrix[i][j] ;
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;

        }
    }
}

void reverse(int** matrix, int matrixSize, int* matrixColSize){
    for ( int i = 0; i< matrixSize; i++){
        int right = *matrixColSize - 1;
        int left = 0;
        while (left < right){
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
            left++;
            right--;
        }
    }
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){ // **matrix pointer to a pointer, pointer to a row? 
    transpose(matrix, matrixSize, matrixColSize);
    reverse(matrix, matrixSize, matrixColSize);
}