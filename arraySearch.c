#include<stdio.h>
#include<stdlib.h>
// this program demonstrates how to search for an element when duplicates are present in the array and we want to find the first occurrence of the target element


int BinarySearch(int*arr, int low, int high, int target){
    int mid;
    int result = -1; // initialize result to -1 to indicate not found
    while( low < high){
        mid = low + (high - low) / 2;
        if( arr[mid] == target){
            result =  mid;
            high = mid-1; // continue searching in the left half to find the first occurrence of the target element

        }
        else if( arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }



    }
    return result; // return the index of the first occurrence of the target element, or -1 if not found
}

int main(void){
    int arr[] = {1, 2, 3, 4, 5, 5, 5, 6, 7, 8,9,10,11,12,13,14,15,16,17,18,19,20};
    
    int size = sizeof(arr) / sizeof(arr[0]); // calculate the size of the array


    int low = 0;
    int high = size - 1;
    int target = 5;
    int result =BinarySearch(arr,low,high,target);

    if( result != -1){
        printf("Element %d found at index %d\n", target, result);
    }
    else{
        printf("Element %d not found\n", target);
    }
    //free(arr); // free the allocated memory to prevent memory leaks
    return 0;
}
