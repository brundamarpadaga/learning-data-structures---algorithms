#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// implementing stack using array 
// traditionally stack is implemented using linked list but here we are implementing stack using array to demonstrate the concept of stack and how it works in memory
// stack grows downwards in memory and we can use an array to represent the stack. We will use a pointer to keep track of the top of the stack and an array to store the elements of the stack. We will also use a structure to represent the stack and its operations.
typedef struct Stack{
    char *stackArray;
    int size;
    char *top;
    struct Stack *self;

    void (*pushPtr)(struct Stack*, char);
    char (*popPtr) (struct Stack*);
    void (*ptrPrint)(struct Stack*);
    int (*getSizePtr)(struct Stack*);
    bool (*isEmptyPtr)(struct Stack*);
    bool (*isFullPtr)(struct Stack*);
    char (*peekPtr)(struct Stack*);
    void (*deletePtr)(struct Stack*);
    

}Stack_t;

void push(Stack_t* stack, char data);
char pop(Stack_t* stack);
void print(Stack_t* stack);
int getSize(Stack_t* stack);
bool isEmpty(Stack_t* stack);
bool isFull(Stack_t* stack);
char peek(Stack_t* stack);
void delete(Stack_t* stack);


Stack_t* newStack(int size){

    Stack_t* newStack = (Stack_t*)malloc(sizeof(Stack_t));

    newStack->stackArray = (char*) malloc(sizeof(char)*size);
    newStack->top = newStack->stackArray+(size); // initialize top to point to the end of the array (stack grows downwards)
    newStack->self = newStack;
    newStack->size = size;

    newStack->ptrPrint = print;
    newStack->popPtr = pop;
    newStack->pushPtr = push;
    newStack->getSizePtr = getSize;
    newStack->isEmptyPtr = isEmpty;
    newStack->isFullPtr = isFull;
    newStack->peekPtr = peek;
    newStack->deletePtr = delete;
    return newStack;
}
void push( Stack_t* stack, char data){
    
    printf("Pushing data: %c \n", data);
    if( stack->top == stack->stackArray){ // check for stack overflow
        printf("Stack overflow! Cannot push data: %c \n", data);
        return;
    }
    stack->top--; // move top pointer down
    *stack->top = data;
    
}

char pop(Stack_t* stack){
    
    if ( isEmpty(stack) ){ // check for stack underflow
        printf("Stack underflow! Cannot pop data from an empty stack \n");
        return -1; // return -1 to indicate stack is empty
    }
    char topData = *stack->top;
    stack->top++;
    printf("Popped data: %c \n", topData);
    return topData;
}

int getSize(Stack_t* stack){
    return stack->size;
}

char peek(Stack_t* stack){
    if( isEmpty(stack) ){
        printf("Stack is empty \n");
        return -1;
    }
    return *stack->top;
}

bool isEmpty(Stack_t* stack){
    return stack->top == stack->stackArray+(stack->size); // stack is empty if top points to the end of the array
}

bool isFull(Stack_t* stack){
    return stack->top == stack->stackArray; // stack is full if top points to the beginning of the array
}

void print(Stack_t* stack){
    printf("TOP -> ");
    if( stack->top == stack->stackArray+(stack->size) ){
        printf("Stack is empty \n");
        return;
    }
    char* temp = stack->top;
    while( temp < stack->stackArray+(stack->size)){ // print stack from top to bottom
        printf("%c -> ", *temp);
        temp++; // move down the stack
    }
    printf("BOTTOM \n");
    printf("Stack size:   %d \n", stack->size);
    printf("Stack top:    %c \n", *stack->top);
    printf("Stack bottom: %c \n", *(stack->stackArray+(stack->size-1)));
    printf("stack starting address: %p \n", stack->stackArray);
    printf("stack end address:      %p \n", stack->stackArray+(stack->size-1));
    printf("stack top address:      %p \n", stack->top);
    printf("stack self address:     %p \n", stack->self);

}

void delete(Stack_t* stack){
    free(stack->stackArray);
    free(stack);
}

/*
int main(){
    Stack_t* s1 = newStack(100);

    s1->pushPtr(s1->self, 'a');
    s1->pushPtr(s1->self, 'b');
    s1->pushPtr(s1->self, 'c');
    s1->pushPtr(s1->self, 'd');
    s1->pushPtr(s1->self, 'e');

    s1->ptrPrint(s1->self);
    printf("\n");

    printf("Stack size: %d \n", s1->getSizePtr(s1->self));
    printf("Stack is empty: %s \n", s1->isEmptyPtr(s1->self) ? "Yes" : "No");
    printf("Stack is full: %s \n", s1->isFullPtr(s1->self) ? "Yes" : "No");
    printf("Stack top: %c \n", s1->peekPtr(s1->self));

    s1->popPtr(s1->self);
    s1->popPtr(s1->self);
    s1->popPtr(s1->self);
    s1->popPtr(s1->self);
    s1->popPtr(s1->self);
    s1->popPtr(s1->self); // this will cause stack underflow



    s1->ptrPrint(s1->self);

    s1->deletePtr(s1->self);

    return 0;
}
*/