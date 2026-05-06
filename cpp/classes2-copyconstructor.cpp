#include<iostream>

class Array{
    
    public:
    // Constructor to initialize the array
    Array(int size){
        this->size = size;
        array = new int[size];
        for(int i = 0; i < size; i++){
            array[i] = i;
        }
    }

    void printArray() const {
        for(int i = 0; i < size; i++){
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
    void updateArray(int index, int value) {
        if(index >= 0 && index < size) {
            array[index] = value;
        }
        else{
            std::cout << "WARNING: index out of bounds" << std::endl;
        }
    } 

    // copy constructor
    Array(const Array &rhs){
        count++;
        size = rhs.size;
        array = new int[size];
        std::cout<< "copy constructor" << std::endl;
        std::cout << "Object count: " << count << std::endl;
        for(int i=0; i<size;i++){
            array[i] = rhs.array[i];
        }
    }

    // copy assignment operator
    // object already exists and we are assigning a copy of another object to it
    Array& operator=(const Array &rhs){
        count++;
        if(this == &rhs){
            return *this; // self assignment check
        }
        delete[] array;
        size = rhs.size;
        array = new int[size];
        std::cout<< "copy assignment operator" << std::endl;
        std::cout << "Object count: " << count << std::endl; // to show that copy assignment operator is called and thus count is incremented
        for(int i=0; i<size;i++){
            array[i] = rhs.array[i];
        }
        return *this;
    }


    ~Array(){
        delete[] array;
    }
    private:
    int* array;
    int size;
    static int count ; // to keep track of number of objects created, includes all objects created through copy constructor and copy assignment operator, to show that they are being called when we expect them to be called
};

int Array::count = 0; // Definition of static member

// BEFORE: pass by value to the function printArray, which will cause a copy of the array object to be created and thus copy constructor will be called, which is inefficient and unnecessary as we only want to print the array and not modify it
void printArray(const Array& arr){ // passing by reference to avoid unnecessary copying of the array object, but still we can see that copy constructor is called when we pass arr1 by value to this function in the main function
    arr.printArray();    
}


int main(){
    Array arr1(5); // Create an array of size 5
    arr1.printArray();
    Array arr2 = arr1; // No compiler error, but this will cause a shallow copy without a user defined copy constructor and thus arr1 and arr2 will point to the same memory location
    arr1.updateArray(1,9999);
    arr1.printArray();
    arr2.printArray(); // BEFORE: change in array1 changed arr2 because arr2 basically is pointing to same memory location and is not its own individual object
    // resulting in double freeing of same memory if copy constructor is not defined and thus causing a runtime error
    // AFTER: with copy constructor defined, arr2 is its own individual object and thus change in arr1 does not affect arr2
    Array arr3(10);
    arr3.printArray();
    Array arr4 = arr3; // copy constructor is called
    arr3 = arr1; // copy assignment operator is called
    arr3.printArray();

    for(int i = 0; i < 100; i++){
        printArray(arr1); // copy constructor is called when passing arr1 by value to the function printArray
    }
    return 0;
}