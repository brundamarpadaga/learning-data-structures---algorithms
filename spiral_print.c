
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize);


/* 1 2 3
 * 4 5 6     =>  1 2 3 6 9 8 7 4 5 => 0,0 0,1 0,2 1,2 2,2 2,1 2,0 1,0 1,1
 * 7 8 9
 * 
 * 
 * 1  2  3  4
 * 5  6  7  8  
 * 9  10 11 12
 * 13 14 15 16
 */

 /* pseudocode :
 while i or j reaches a boundary, the other should progress , and then alternative should regress to lower boundary 

 boundaries : top bottom right left
 */

 int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){

    int* resultArray = (int*) malloc((*returnSize) * sizeof(int));

    int top = 0;
    int bottom = matrixSize - 1;
    int left = 0;
    int right = *matrixColSize - 1;
    int index = 0, j = 0, k = 0;
    while ( left<= right && top <= bottom ){
        //resultArray[i] = matrix[j][k];
        printf("i: %d, j: %d, k: %d, top: %d, bottom: %d, left: %d, right: %d\n", index, j, k, top, bottom, left, right);
        printf("resultArray[%d] = matrix[%d][%d] = %d\n", index, j, k, matrix[j][k]);
        for(int i = left; i<= right; i++){
            resultArray[index++] = matrix[top][i];
        }
        top++;
        for(int i = top; i<= bottom; i++) resultArray[index++] = matrix[i][right];
        right--;
        
        for(int i = right; i>= left; i-- ) resultArray[index++] = matrix[bottom][i];
        bottom--;
        
        for (int i = bottom; i>= top; i--) resultArray[index++] = matrix[i][left];
        left++;

    }
    return resultArray;
 }

 int main(){

    
    int colSize = 4;
    int* matrixColSize = &colSize;
    int matrixSize = 4;
    int** matrix = (int**) malloc(matrixSize * sizeof(int*));
    for (int i = 0; i < matrixSize; i++){
        matrix[i] = (int*) malloc(*matrixColSize * sizeof(int));
    }
    for (int i = 0; i < matrixSize; i++){
        for(int j = 0; j < *matrixColSize; j++){
              matrix[i][j] =  i * (*matrixColSize) + j + 1;
          }
      }

      int* returnSize = (int*) malloc(sizeof(int));
      *returnSize = matrixSize * (*matrixColSize);
      printf("returnSize: %d\n", *returnSize);
      int* result = spiralOrder(matrix, matrixSize, matrixColSize, returnSize);
      for (int i = 0; i < *returnSize; i++){
        printf("%d ", result[i]);
      }
      printf("\n");

    // free the memory
    for (int i = 0; i < matrixSize; i++){
        free(matrix[i]);
    }
    free(matrix);
    free(returnSize);
    free(result);
    
    return 0;
 }


