#include<stdio.h>
#include<stdlib.h>

int binarySearch(int* arr, int low, int high, int target){
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int findPosition(int* arr, int target){
    int low = 0;
    int high = 1;

    while( arr[high] < target){
        low = high;
        high *= 2; // double the high index to expand the search range exponentially
    }

    return binarySearch(arr, low, high, target); // perform binary search in the identified range
    
}


int main(void){

    int size = 1000;
    int* arr = (int*) malloc ( size * sizeof(int) ); // heap allocated array of size 1000

    for(int i = 0; i < size; i++){
        arr[i] = i * 3; // initialize array elements
    }
    printf("%d\n", arr[999]); // print the last element to verify initialization
    int target = 408;

    int result = findPosition(arr, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found\n", target);
    }

    free(arr); // free the allocated memory to prevent memory leaks


    return 0;
}