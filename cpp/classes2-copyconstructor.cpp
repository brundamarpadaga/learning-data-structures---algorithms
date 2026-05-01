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
        delete[] array;
        size = rhs.size;
        array = new int[size];
        std::cout<< "copy constructor" << std::endl;
        for(int i=0; i<size;i++){
            array[i] = rhs.array[i];
        }
    }

    // copy assignment operator
    // object already exists and we are assigning a copy of another object to it
    Array& operator=(const Array &rhs){
        
        if(this == &rhs){
            return *this; // self assignment check
        }
        delete[] array;
        size = rhs.size;
        array = new int[size];
        std::cout<< "copy assignment operator" << std::endl;
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
};


int main(){
    Array arr1(5); // Create an array of size 5
    arr1.printArray();
    Array arr2 = arr1; // No compiler error, but this will cause a shallow copy without a user defined copy constructor and thus arr1 and arr2 will point to the same memory location
    arr1.updateArray(1,9999);
    arr1.printArray();
    arr2.printArray(); // change in array1 changed arr2 because arr2 basically is pointing to same memory location and is not its own individual object
    // resulting in double freeing of same memory if copy constructor is not defined and thus causing a runtime error
    Array arr3(10);
    arr3.printArray();
    arr3 = arr1; // copy assignment operator is called
    arr3.printArray();
    return 0;
}