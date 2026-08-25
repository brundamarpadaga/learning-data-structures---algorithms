/*
 * File: main.c
 * 
 * Code taken from "Extreme C" by Kamran Amini, Chapter 5: Inheritance in C
 * 
 */


#include<stdio.h>
#include<stdlib.h>
#include"student.h"
#include"person.h"


int main(){
    
    printf("Learning about public API of base class in C17! \n");
    student_t* student = newStudent(); // create a new student object
    student_ctor(student, "John", "Doe", 20, 12345, B); // initialize the student object, we still don't know about person class
    printStudent(student); // print the student object

    person_t* person_ptr = (person_t*)student; // cast the student object to person object

    // printf("First Name: %s\n", person_get_firstName(student->person));// won't work since person is a pointer to the base class (person_t) and we don't have access to it in main.c, we can only access it through the public API of student_t

    printf("First Name: %s\n", getStudentFirstName(student)); // get the first name of the person object
    printf("Last Name: %s\n", getStudentLastName(student)); // get the last name of the person object
    printf("Age: %d\n", getStudentAge(student)); // get the age of the person object


    student_dtor(student); // destroy the student object
    free(student); // free the memory allocated for the student object; here because main owns the student object
    return 0;
}