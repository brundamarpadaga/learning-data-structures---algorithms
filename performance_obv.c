#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void fill_matrix(int* matrix, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            matrix[i*cols + j] = rand() % 100;
        }
    }
}


void print_matrix(int* matrix, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i*cols + j]);
        }
        printf("\n");
    }
}

void sum_friendly(int* matrix, int rows, int cols){
    int sum = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            sum += matrix[i*cols + j];
        }
    }
    printf("Sum of all elements: %d\n", sum);
}

void sum_unfriendly(int* matrix, int rows, int cols){
    int sum = 0;
    for ( int j =0;j<cols;j++){
        for(int i = 0 ; i < rows; i++){
            sum += matrix[i*cols + j];
        }
    }
    printf("Sum of all elements: %d\n", sum);
}
int main(int argc, char* argv[]){
    if(argc!= 4){
        fprintf(stderr, "Usage: %s <operation> <rows> <cols>\n", argv[0]);
        return 1;
    }

    char *operation = argv[1];
    int rows = atoi(argv[2]);
    int cols = atoi(argv[3]);

    int* matrix = (int*)malloc(rows * cols * sizeof(int));
    if (!matrix) {
        fprintf(stderr, "Matrix allocation failed\n");
        return 1;
    }
    
    clock_t start, end;
    double cpu_time_used;

    fill_matrix(matrix, rows, cols);

    if( strcmp(operation, "friendly") == 0){
        start = clock();
        sum_friendly(matrix, rows, cols);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("sum_friendly took %f seconds to execute \n", cpu_time_used);
    }
    else if( strcmp(operation, "unfriendly") == 0){
        start = clock();
        sum_unfriendly(matrix, rows, cols);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("sum_unfriendly took %f seconds to execute \n", cpu_time_used);
    }
    else{
        fprintf(stderr, "Invalid operation. Please use 'friendly' or 'unfriendly'.\n");
        return 1;
    }

    free(matrix);
    return 0;
}