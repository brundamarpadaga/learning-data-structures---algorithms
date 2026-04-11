#include <iostream>

void print(int& x) {
    std::cout << "Lvalue reference: " << x << std::endl;
}

// Overloaded function for rvalue references
void print(int&& x) {
    std::cout << "Rvalue reference: " << x << std::endl;
}

int main() {
    int a = 10; // 'a' is an lvalue
    print(a);   // Calls the lvalue reference version

    print(20);  // Calls the rvalue reference version, generates a temporary rvalue with the value 20 

    return 0;
}