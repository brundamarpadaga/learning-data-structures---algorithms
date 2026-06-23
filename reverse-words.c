#include<stdio.h>


void reverseWords(char* string){
    char *left = string;
    char *right = string;
    
    while(*right != '\0'){
        right++;
    }
    while(left<right){
        char* temp = left;
        left = right;
        right = temp;
        left++;
        right--;
    }
}

int main(){

    char string[6] = {'H','E','L','L','L','O'} ;

    reverseWords(string);

    printf("%s \n", string);



}