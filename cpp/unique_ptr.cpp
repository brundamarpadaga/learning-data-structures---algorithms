#include<iostream>
#include<memory> // for std::unique_ptr


class UDT{
    int value;
    public:
    UDT(int val) : value(val) {
        std::cout << "UDT constructor called with value: " << value << std::endl;
    }
    ~UDT(){
        std::cout << "UDT destructor called with value: " << value << std::endl;
    }
};

int main(){
    UDT udt(100); // create a unique_ptr to a UDT object with value 100
    std::unique_ptr<UDT> ptrUDT; // create a unique_ptr 
    ptrUDT = std::unique_ptr<UDT>(new UDT(200)); // assign a new UDT object to ptrUDT, the old UDT object will be destroyed when ptrUDT is assigned a new value
    std::unique_ptr<int> ptr1(new int(42)); // create a unique_ptr to an integer with value 42

    std::cout << "Value at ptr1: " << *ptr1 << std::endl; // dereference ptr1 to get the value

    // std::unique_ptr<int> ptr2 = ptr1; // This will cause a compile-time error because unique_ptr cannot be copied
    std::unique_ptr<int> ptr2 = std::move(ptr1); // transfer ownership from ptr1 to ptr2 using std::move
    std::cout << "Value at ptr2: " << *ptr2 << std::endl; // dereference ptr2 to get the value

    if (ptr1) {
        std::cout << "ptr1 is not null" << std::endl;
    } else {
        std::cout << "ptr1 is null after move" << std::endl; // ptr1 should be null after move
    }

    return 0;
}