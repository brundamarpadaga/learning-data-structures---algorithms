// Practicing all the data structures in C17 starting from arrays, dynamic arrays
#include<stdio.h>
#include<stdlib.h>
#include "datastructures.h"


void pointerArithmeticDemo();
int main(){
    printf("Hello, Data Structures in C17!\n");
    int array[5] = {1, 2, 3, 4, 5};
    int size = sizeof(array)/sizeof(array[0]); // calculating size of the array

    

    printf( "sizeof(array) in bytes is: %d\n", sizeof(array)); // size in bytes
    printf( "Number of elements in array is (size): %d\n", size); // number of elements

    updateElement(array[1], 50); // passing array element by value
    printf("After updateElement call, array[1] = %d\n", array[1]); // should still be 2

    updateElementByRef(&array[1], 50); // passing address of array element
    printf("After updateElementByRef call, array[1] = %d\n", array[1]); // should be updated to 50


    for ( int i = 0; i < size; i++){
        printf("array[%d] = %d \n", i, array[i]); // accessing array elements using index
    }

    array[2] = 10; // modifying array element at index 2
    //printf("After modification, array[2] = %d\n", array[2]);
    int* ptrToArray = array;  
    int sum = addElementsInArray(ptrToArray, size); // passing array to function using pointer
    printf("Sum of array elements: %d\n", sum);
    

    printArray(ptrToArray,size); // using pointer to pass array to function
    
    pointerArithmeticDemo();

    student_t stu1 = {"Alice", 20, 3.5};
    printStudent(&stu1);
    return 0;
}

void printStudent(student_t* stu){
    printf("Name: %s, Age: %d, GPA: %.2f\n", stu->name, stu->age, stu->gpa);
}

void printArray( int* arr,int size){ // arr is a pointer to the first element of the array 
    arr[3] = 20; // modifying the first element of the array through pointer
    for( int i = 0; i < size; i++){
        printf("array[%d] = %d ",i, arr[i]);
    }
    printf("\n");

}

void updateElement( int a, int value){
    a = value; // this will not modify the original array element, a is a copy!!
}

void updateElementByRef( int* a, int value){ // a is a pointer to the array element
    *a = value; // this will modify the original array element
}

int addElementsInArray(int* arr, int size){ // send address of first element
    int sum = 0;
    for( int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}

void pointerArithmeticDemo(){
    int arr[5] = {10, 20, 30, 40, 50};

    int *ptr = arr; // pointer to the first element
    int *ptr2 = &arr[0]; // pointer to the first element

    printf("addresses %p %p %p %p ", ptr, ptr2, &arr[0], (void*)arr);
}