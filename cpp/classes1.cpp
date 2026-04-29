#include<iostream>

class Student {
    private:
    std::string name;
    int age;
    public:
    Student(std::string name, int age) : name(name), age(age) {}
    void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
    std::string getName() const { // const member function to get the name of the student
        return name;
    }
    int getAge() const {
        return age;
    }
    void setName(std::string newName) {
        name = newName;
    }
    void setAge(int newAge) {
        age = newAge;
    }
    ~Student() {
        std::cout << "Destructor called for " << name << std::endl;
    }
};

int main(){

    Student student1("Alice", 20);
    student1.displayInfo();

    Student student2("Bob", 22);
    student2.displayInfo();


    return 0;


}