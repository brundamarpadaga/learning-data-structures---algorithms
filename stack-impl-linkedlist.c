#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <assert.h>

// implementing stack using linked list

typedef struct Node{
    int data;
    struct Node* next;
} Node_t;

typedef struct Stack{
    Node_t* top;
} Stack_t;

Stack_t* newStack(){
    Stack_t* new = (Stack_t*) malloc( sizeof(Stack_t));
    if( new == NULL){
        printf("Out of heap memory. Could not allocate memory for a new stack. \n");
        return NULL;
    }
    new->top = NULL;
    return new;
}

void push ( Stack_t* stack, int data){
    Node_t* node = (Node_t*) malloc( sizeof(Node_t));
    if( node == NULL){
        printf("System out of heap memory. Failed to allocate space for data \n");
        return;
    }
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

bool pop( Stack_t* stack, int* outData){
    if(stack->top == NULL){
        printf("Stack underflow!! \n");
        return false;
    }
    Node_t* temp = stack->top;
    *outData = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return true;
}

bool peek( Stack_t* stack, int* outData){
    if( stack->top == NULL){
        printf("Stack is Empty!! \n");
        return false;
    }
    *outData = stack->top->data;
    return true;
}

void display( Stack_t* stack){
    if( stack->top == NULL){
        printf("stack is empty \n");
        return;
    }
    Node_t* temp = stack->top;
    while( temp!= NULL ){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void deleteStack(Stack_t* stack){
    Node_t* temp = stack->top;
    while( temp!= NULL){
        Node_t* next = temp->next;
        free(temp);
        temp = next;
    }
    free(stack);
}
int main(){
    int outData ;
    Stack_t* stack = newStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    display(stack);
    printf("Top of stack: %d \n", peek(stack, &outData) ? outData : -1);

    
    bool success = pop(stack, &outData);

    assert(success);
    printf("Popped element: %d \n", outData );

    success = pop(stack, &outData);
    assert(success);
    printf("Popped element: %d \n", outData);

    success = pop(stack, &outData);
    assert(success);
    printf("Popped element: %d \n", outData);

    success = pop(stack, &outData);
    assert(success);
    printf("Popped element: %d \n", outData);

    success = pop(stack, &outData);
    assert(success);
    printf("Popped element: %d \n", outData);

    printf("Popped element: %d \n", pop(stack, &outData)? outData : -1);

    
    display(stack);
    
    printf("Top of stack: %d \n", peek(stack, &outData) ? outData : -1);
    
    deleteStack(stack);
    return 0;
}