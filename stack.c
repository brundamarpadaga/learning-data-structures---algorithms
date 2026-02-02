#include<stdio.h>
/* Stack is a LIFO (Last In First Out) data structure 


main


main return address
30
40
fun2 return address
50
60
fun3 return address


*/


void fun1(){
    int a = 10; // push onto the stack
    int b = 20; // push onto the stack
    // pops automatically when function ends, memory is reclaimed
}
void fun2(){
    int x = 30; // push onto the stack
    int y = 40; // push onto the stack
    fun3(); // representing the stack at this point
    // pops automatically when function ends, memory is reclaimed
}
void fun3(){
    int p = 50; // push onto the stack
    int q = 60; // push onto the stack
    // pops automatically when function ends, memory is reclaimed
}

int* dangerousFunction(){
    int z = 100; // local variable on stack
    return &z; // returning address of local variable (dangerous)
    // x gets popped and &z becomes a dangling pointer 
}

void iterativeFunction(){
    int i[300];
    char ch[5000];
    iterativeFunction(); // stack overflow due to too much memory usage.  AVOID!!
}

void main(){
    printf("Learning about Stacks! \n");


    fun1();

    fun2(); 
}