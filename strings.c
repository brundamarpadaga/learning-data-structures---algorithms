#include <stdio.h>

char* stringAppend(char*dest, char* src){
    char *ptr = dest; // pointer to traverse dest string
    while(*ptr != '\0'){
        ptr++; // move to the end of dest string
    }
    while( *src!= '\0'){
        *ptr = *src; // copy character from src to dest
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}

char* reverseString( char* str){
    char* temp = str;

    while( *temp != '\0'){
        temp++;
    }
    temp--; // point to last character
    char *start = str;

    while( start <  temp){
        char ch = *start;
        *start = *temp;
        *temp = ch;
        start++;
        temp--;
    }
    return str;
}

size_t sizeOfString( char* str){
    int count = 0;
    while( *str != '\0'){
        count++;
        str++;
    }
    return count;
}



int main(){
    printf("Learning about Strings! \n");

    char str1[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', '\0'}; // char array with explicit null terminator
    char str2[] = {'W', 'o', 'r', 'l', 'd', '!', '\0'}; // char array with explicit null terminator
    char str3[50] = " This is a string in C."; // string literal initialization

    // custom string append function
    stringAppend(str1, str2);
    stringAppend(str3, str1);
    printf("Appended String: %s\n", str1);
    printf("Final String: %s\n", str3);
    // custom reverse string function
    reverseString(str3);
    printf("Reversed String: %s\n", str3);
    // custom size of string function
    int len = sizeOfString(str3);
    printf("Length of Reversed String: %d\n", len);

    return 0;
}