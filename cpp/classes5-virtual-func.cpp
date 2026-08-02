#include<iostream>



class Base{
    public:
    Base(){
        std::cout << "Base constructor called" << std::endl;
    }
    ~Base(){
        std::cout << "Base destructor called" << std::endl;
    }

    virtual void display(){ // virtual function allows derived class to override this function
        std::cout << "Base display function called" << std::endl;
    }
};

class Derived : public Base{
    public:
    Derived(){
        std::cout << "Derived constructor called" << std::endl;
    }
    ~Derived(){
        std::cout << "Derived destructor called" << std::endl;
    }
    void display() override { // override specifier indicates that this function overrides a virtual function in the base class
        std::cout << "Derived display function called" << std::endl;
    }
};

int main(){

    Base* basePtr = new Derived(); // Base class pointer pointing to Derived class object
    basePtr->Base::display(); // Calls the display function of the Base class, not the Derived class

    delete basePtr; // Calls the destructor of the Base class, not the Derived class

    return 0;
}


