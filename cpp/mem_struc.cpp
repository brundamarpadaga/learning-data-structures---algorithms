// this program is for observing the memory structure of inherited classes in C++


#include <iostream>

class A{
    int a;
    int b;
};

class B {
    float c;
    char d;
    char e[5] = "abcd";
};

class C : public A, public B {
    int f;
    int g;
};

int main() { // place a breakpoint here and observe the memory structure of the classes in the debugger, -g 
    std::cout << "Size of class A: " << sizeof(A) << " bytes" << std::endl;
    std::cout << "Size of class B: " << sizeof(B) << " bytes" << std::endl;
    std::cout << "Size of class C: " << sizeof(C) << " bytes" << std::endl;

    return 0;
}