#include <iostream>

int main(){
    int *ptr = new int; // dynamically allocate memory for an integer and assign its address to ptr

    *ptr = 42; // assign a value to the allocated memory

    char* charPtr = (char*)ptr; // assign the address stored in ptr to charPtr (type mismatch, but allowed in C++)

    std::cout << "First Byte in memory = 0x" << std::hex << (int)(unsigned char)(charPtr[0]) << std::endl; // dereference charPtr
    std::cout << "Address of charPtr = " << static_cast<void*>(charPtr) << std::endl; // print the address stored in charPtr
    std::cout << "Second Byte in memory = 0x" << std::hex << (int)(unsigned char)(charPtr[1]) << std::endl; // dereference charPtr
    std::cout << "Address of second byte = " << static_cast<void*>(charPtr+1) << std::endl; // print the address stored in charPtr
    std::cout << "Third Byte in memory = 0x" << std::hex << (int)(unsigned char)(charPtr[2]) << std::endl; // dereference charPtr
    std::cout << "Fourth Byte in memory = 0x" << std::hex << (int)(unsigned char)(charPtr[3]) << std::endl; // dereference charPtr
    std::cout << "Value at address stored in ptr = " << *ptr << std::endl; // dereference ptr to get the value at the allocated memory
    std::cout << "Address stored in ptr = " << ptr << std::endl; // print the address stored in ptr

    delete ptr; // deallocate the memory to prevent memory leaks
}