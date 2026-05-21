#include <iostream>
#include <utility> // for std::move

void print(int& x) {
    std::cout << "Lvalue reference: " << x << std::endl;
}

void print(int&& x) { // takes an rvalue reference, can only bind to rvalues
    std::cout << "Rvalue reference: " << x << std::endl;
}

void print(const int& x) { // takes a const lvalue reference, can bind to both lvalues and rvalues
    std::cout << "Const lvalue reference: " << x << std::endl;
}

int returnRvalue(){
    return 30; // returns an rvalue
}
int globalVar = 400; // global variable is an lvalue

// Function that returns an lvalue reference
int& returnLvalue(){
    return globalVar; // returns an lvalue, globalVar has locatable storage and an identifiable location in memory
}

// why print(int x) doesn't work
// Because print(int x) takes the value by value, not by reference, so it creates a copy of the argument

// lvalue reference: can bind to lvalues and is used to pass arguments by reference to avoid copying
// rvalue reference: can bind to rvalues and is used to pass arguments by reference to avoid copying
// const lvalue reference: can bind to both lvalues and rvalues, and is used to pass arguments by reference to avoid copying while ensuring the value cannot be modified
// what is lvalue and rvalue in C++?
// In C++, an lvalue (left value) is an expression that refers to a memory location and can appear on the left side of an assignment.
// An rvalue (right value) is an expression that does not refer to a memory location and can only appear on the right side of an assignment.
int main() {
    int a = 10; // 'a' is an lvalue
    print(a);   // Calls the lvalue reference version

    print(20);  // Calls the rvalue reference version, generates a temporary rvalue with the value 20 
                // Calls the const lvalue reference version, since it can bind to rvalues
    print(std::move(a)); // std::move converts 'a' to an rvalue, calls the rvalue reference version
                        // This allows the value to be moved rather than copied, which can be more efficient
    print(returnRvalue()); // Calls the rvalue reference version, returnRvalue() returns an rvalue
    print(returnLvalue()); // Calls the lvalue reference version, returnLvalue() returns an lvalue
    return 0;
}