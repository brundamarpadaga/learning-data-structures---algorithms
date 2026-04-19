#include<iostream>
#include<memory> // for std::unique_ptr

class UDT{
    private:
    int value;
    public:
    UDT(int val) : value(val) {
        std::cout << "UDT constructor called with value: " << value << std::endl;
    }
    ~UDT(){
        std::cout << "UDT destructor called with value: " << value << std::endl;
    }
    int getValue() const{
        return value;
    }
};

int main(){
    UDT udt(100);
    std::shared_ptr<UDT> ptrUDT1; // create a shared_ptr to UDT, initially null
    ptrUDT1 = std::shared_ptr<UDT>(&udt); // assign the address of udt to ptrUDT1, this is not recommended as it can lead to double deletion when ptrUDT1 goes out of scope and tries to delete udt which is not allocated on heap
    std::shared_ptr<UDT> ptrUDT2 = ptrUDT1; // copy ptrUDT1 to ptrUDT2, both shared_ptrs now share ownership of the same object (udt), this is not recommended as udt is not allocated on heap
    std::cout << "Value at ptrUDT1: " << ptrUDT1->getValue() << std::endl; // access value through ptrUDT1
    std::cout << "Value at ptrUDT2: " << ptrUDT2->getValue() << std::endl; // access value through ptrUDT2
    std::cout << "Use count: " << ptrUDT1.use_count() << std::endl; // print the use count, should be 2 as both ptrUDT1 and ptrUDT2 share ownership of udt
    
    {
        std::shared_ptr<UDT> ptrUDT3 = ptrUDT2; // create a new shared_ptr ptrUDT3 that shares ownership of udt with ptrUDT2, this is not recommended as udt is not allocated on heap
        std::cout << "Value at ptrUDT3: " << ptrUDT3->getValue() << std::endl; // access value through ptrUDT3
        std::cout << "Use count: " << ptrUDT3.use_count() << std::endl; // print the use count
    }
    ptrUDT1.reset(); // reset ptrUDT1 to null
    std::cout << "After resetting ptrUDT1:" << std::endl;
    std::cout << "Value at ptrUDT2: " << ptrUDT2->getValue() << std::endl; // access value through ptrUDT2
    std::cout << "Use count: " << ptrUDT2.use_count() << std::endl; // print the use count, should still be 1 as ptrUDT2 still owns udt
    
    return 0;
}