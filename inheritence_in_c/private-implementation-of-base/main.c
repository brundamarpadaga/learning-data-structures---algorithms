#include<stdio.h>
#include"student.h"


int main(){
    
    printf("Learning about private implementation of base class in C17! \n");
    student_t* student = newStudent(); // create a new student object, we don't know about person class
    student_ctor(student, "John", "Doe", 20, 12345, A); // initialize the student object
    printStudent(student); // print the student object

    getStudentFirstName(student); // get the first name of the student
    return 0;
}