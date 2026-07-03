#include<stdio.h>

// Function to reverse a string in place
void reverseString(char* string){
    char *left = string;
    char *right = string;
    
    while(*right != '\0'){
        right++;
    }
    right--; // point to the last character of the string
    while(left<right){
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

// Function to reverse the words in a string
void reverseWords(char* string){
    reverseString(string);
    char* charIter = string ; // this points to the current character in the string
    char* start = string; // get the start of the word and attach a /0 when space is found
    while( *charIter!= '\0'){
        
        if( *charIter == ' ' ){
            *charIter = '\0'; // terminate the word
            reverseString(start);
            *charIter = ' '; // put back the space
            start = charIter + 1; // set the start to the next word
        }       
        charIter++; // move to the next character

    }

}

int main(){

    char string[50] = "this is a string in C."; ;

    reverseWords(string);

    printf("%s \n", string);



}