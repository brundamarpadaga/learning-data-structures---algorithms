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

int& returnLvalue(){
    return globalVar; // returns an lvalue, globalVar has locatable storage and an identifiable location in memory
}

int main() {
    int a = 10; // 'a' is an lvalue
    print(a);   // Calls the lvalue reference version

    print(20);  // Calls the rvalue reference version, generates a temporary rvalue with the value 20 
                // Calls the const lvalue reference version, since it can bind to rvalues
    print(std::move(a)); // std::move converts 'a' to an rvalue, calls the rvalue reference version
    
    print(returnRvalue()); // Calls the rvalue reference version, returnRvalue() returns an rvalue
    print(returnLvalue()); // Calls the lvalue reference version, returnLvalue() returns
    return 0;
}