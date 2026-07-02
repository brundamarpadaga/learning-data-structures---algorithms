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
    char* wordIter = *(string) ; // get the start of the word and attach a /0 when space is found
    char* start = string;
    while( *string!= '\0'){
        
        if( *(string) == ' '){
            *wordIter = '/0';
            reverseString(start);
            start = ++string;

        }
        else{
            *wordIter = *string;
            wordIter++;
            string++;
        }

    }

}

int main(){

    char string[50] = "this is a string in C."; ;

    reverseWords(string);

    printf("%s \n", string);



}