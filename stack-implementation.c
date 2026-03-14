#include<stdio.h>
#include<stdlib.h>

// implementing stack using array 
// traditionally stack is implemented using linked list but here we are implementing stack using array to demonstrate the concept of stack and how it works in memory
// stack grows downwards in memory and we can use an array to represent the stack. We will use a pointer to keep track of the top of the stack and an array to store the elements of the stack. We will also use a structure to represent the stack and its operations.
typedef struct Stack{
    int *stackArray;
    int size;
    int *top;
    struct Stack *self;

    void (*pushPtr)(struct Stack*, int);
    int (*popPtr) (struct Stack*);
    void (*ptrPrint)(struct Stack*);
    int (*getSizePtr)(struct Stack*);
    int (*isEmptyPtr)(struct Stack*);
    int (*isFullPtr)(struct Stack*);
    int (*peekPtr)(struct Stack*);
    void (*deletePtr)(struct Stack*);
}Stack_t;

void push(Stack_t* stack, int data);
int pop(Stack_t* stack);
void print(Stack_t* stack);
int getSize(Stack_t* stack);
int isEmpty(Stack_t* stack);
int isFull(Stack_t* stack);
int peek(Stack_t* stack);
void delete(Stack_t* stack);


struct Stack* newStack(int size){

    Stack_t* newStack = (Stack_t*)malloc(sizeof(Stack_t));

    newStack->stackArray = (int*) malloc(sizeof(int)*size);
    newStack->top = newStack->stackArray+(size); // initialize top to point to the end of the array (stack grows downwards)
    newStack->self = newStack;
    newStack->size = size;

    newStack->ptrPrint = print;
    newStack->popPtr = pop;
    newStack->pushPtr = push;

    return newStack;
}
void push( Stack_t* stack, int data){
    
    printf("Pushing data: %d \n", data);
    if( stack->top == stack->stackArray){ // check for stack overflow
        printf("Stack overflow! Cannot push data: %d \n", data);
        return;
    }
    stack->top--; // move top pointer down
    *stack->top = data;
    
}

int pop(Stack_t* stack){
    int topData = *stack->top;
    if ( stack->top == stack->stackArray+(stack->size) ){ // check for stack underflow
        printf("Stack underflow! Cannot pop data from an empty stack \n");
        return -1; // return -1 to indicate stack is empty
    }
    stack->top++;
    printf("Popped data: %d \n", topData);
    return topData;
}

int getSize(Stack_t* stack){
    return stack->size;
}

int peek(Stack_t* stack){
    return *stack->top;
}

int isEmpty(Stack_t* stack){
    return stack->top == stack->stackArray+(stack->size); // stack is empty if top points to the end of the array
}

int isFull(Stack_t* stack){
    return stack->top == stack->stackArray; // stack is full if top points to the beginning of the array
}

void print(Stack_t* stack){
    printf("TOP -> ");
    int* temp = stack->top;
    while( temp < stack->stackArray+(stack->size)){ // print stack from top to bottom
        printf("%d -> ", *temp);
        temp++; // move down the stack
    }
    printf("BOTTOM \n");
    printf("Stack size:   %d \n", stack->size);
    printf("Stack top:    %d \n", *stack->top);
    printf("Stack bottom: %d \n", *(stack->stackArray+(stack->size-1)));
    printf("stack starting address: %p \n", stack->stackArray);
    printf("stack end address:      %p \n", stack->stackArray+(stack->size-1));
    printf("stack top address:      %p \n", stack->top);
    printf("stack self address:     %p \n", stack->self);

}

int main(){
    Stack_t* s1 = newStack(100);

    s1->pushPtr(s1->self, 5);
    s1->pushPtr(s1->self, 4);
    s1->pushPtr(s1->self, 3);
    s1->pushPtr(s1->self, 2);
    s1->pushPtr(s1->self, 1);

    s1->ptrPrint(s1->self);
    printf("\n");

    printf("Stack size: %d \n", s1->getSizePtr(s1->self));
    printf("Stack is empty: %s \n", s1->isEmptyPtr(s1->self) ? "Yes" : "No");
    printf("Stack is full: %s \n", s1->isFullPtr(s1->self) ? "Yes" : "No");
    printf("Stack top: %d \n", s1->peekPtr(s1->self));

    s1->popPtr(s1->self);
    s1->popPtr(s1->self);
    s1->popPtr(s1->self);
    s1->popPtr(s1->self);
    s1->popPtr(s1->self);
    s1->popPtr(s1->self); // this will cause stack underflow



    s1->ptrPrint(s1->self);

    return 0;
}
