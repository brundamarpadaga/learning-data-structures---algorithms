#include<stdio.h>
#include<stdlib.h>

void print(){
    printf("Hello World \n ");
}

void printInt(int a){
    printf("Value of a = %d \n", a);
}

int add(int a, int b){
    return a+b;
}
int main(){

    int a = 42;
    void* genericPtr = &a;

    printf("Value at address stored in ptr = %d \n", *(int*)genericPtr); // typecast to int pointer to dereference and get value at address stored in genericPtr

    genericPtr = print;
    (*(void(*)())genericPtr)(); // typecast to void pointer to call the function stored in genericPtr

    genericPtr = printInt;
    (*(void(*)(int))genericPtr)(97); // typecast to void pointer to call the function stored in genericPtr with argument a
    
    genericPtr = add;
    int result = (*(int(*)(int,int))genericPtr)(2,5); // typecast to int pointer to assign the address of add function to genericPtr
    printf("Result of add function = %d \n", result);
    
    return 0;
}