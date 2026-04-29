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
        array = new int[size];
        size = rhs.size;
        std::cout<< "copy constructor" << std::endl;
        for(int i=0; i<size;i++){
            array[i] = rhs.array[i];
        }
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
    Array arr2(arr1); // No compiler error, but this will cause a shallow copy
    arr1.updateArray(1,9999);
    arr2.printArray(); // change in array1 changed arr2 because arr2 basically is pointing to same memory location and is not its own individual object
    // resulting in double freeing of same memory
    return 0;
}