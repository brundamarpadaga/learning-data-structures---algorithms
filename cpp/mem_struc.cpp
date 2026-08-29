// this program is for observing the memory structure of inherited classes in C++


#include <iostream>
#include<cstring>

class A{
    public:
    int a ;
    int b ;
};

class B {
    public:
    float c;
    char d ;
    char e[5];
};

class C : public A, public B {
    public:
    int f;
    int g;
};

/*
key gdb commands to use for observing memory structure:
(gdb) next                      # step past variable declarations
(gdb) ptype /o A                # show layout with byte offsets (GDB 8.1+)
(gdb) ptype /o C                # see how A and B are laid out inside C
(gdb) x/8xb &a                  # examine 8 raw bytes of `a` in hex
(gdb) x/20xb &c                 # examine 20 raw bytes of `c` (all members)
(gdb) p &a                      # address of a
(gdb) p &c                      # address of c (= address of A subobject in C)
(gdb) p (A*)&c                  # cast c to A* — same address, proving layout
(gdb) info locals               # see all locals and their addresses */

int main() { // place a breakpoint here and observe the memory structure of the classes in the debugger, -g 
    
    C c ;

    c.f = 10; 
    c.g = 11;

    c.a = 1;
    c.b = 2;
    c.c = 3.14f;
    c.d = 'x';

    strcpy(c.e, "hello");



    std::cout << "Size of class A: " << sizeof(A) << " bytes" << std::endl;
    std::cout << "Size of class B: " << sizeof(B) << " bytes" << std::endl;
    std::cout << "Size of class C: " << sizeof(C) << " bytes" << std::endl;

    return 0;
}