#include<stdio.h>
#include<stdlib.h>

typedef int (*operation_t)(int, int); // Define a function pointer type for operations that take two integers and return an integer

int arithmetic(int(*ptr)(int, int), int a, int b);

int add(int a,int b);
int sub(int a,int b);
int mul(int a, int b);
int divOp(int a , int b);


int main(int argc, char** argv){

    operation_t ptrAdd, ptrSub, ptrMul, ptrDiv;

    //int (*addPtr)(int, int) = add; // Initialize function pointer for addition
    //int (*subPtr)(int, int) = sub; // Initialize function pointer for subtraction
    //int (*mulPtr)(int, int) = mul; // Initialize function pointer for multiplication
    //int (*divPtr)(int, int) = divOp; // Initialize function pointer for

    printf("argc = %d\n", argc);
    printf("argv = %s\n", argv[0]);
    for(int i=1;i<argc;i++){
        printf("%s\n", argv[i]);
    }
    int operand1 = atoi(argv[1]);
    int operand2 = atoi(argv[3]);
    char operator = argv[2][0];
    int result;
    switch(operator){
        case '+':
            ptrAdd = add;
            result = arithmetic(ptrAdd, operand1, operand2);
            break;
        case '-':
            ptrSub = sub;
            result = arithmetic(ptrSub, operand1, operand2);
            break;
        case '*':
            ptrMul = mul;
            result = arithmetic(ptrMul, operand1, operand2);
            break;

        case '/':
            ptrDiv = divOp;
            result = arithmetic(ptrDiv, operand1, operand2);
            break;
        default:
            printf("Invalid operator\n");
            return 1;
    }

    printf("Result: %d\n", result);

    
    return 0;
}

int add(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}
int mul(int a, int b){
    return a*b;
}
int divOp(int a , int b){
    if ( b == 0){
        printf("Cannot divide by zero\n");
        return 0;
    }
    return a/b;
}
int arithmetic(int(*ptr)(int, int), int a, int b){
    (*ptr)(a,b);
}
