/*
 * File: main.c
 * 
 * Code taken from "Extreme C" by Kamran Amini, Chapter 5: Inheritance in C
 * 
 */


#include<stdio.h>
#include"student.h"
#include"person.h"


int main(){
    
    printf("Learning about private implementation of base class in C17! \n");
    student_t* student = newStudent(); // create a new student object, we don't know about person class
    student_ctor(student, "John", "Doe", 20, 12345, A); // initialize the student object
    printStudent(student); // print the student object

    person_t* person_ptr = (person_t*)student; // cast the student object to person object

    printf("First Name: %s\n", person_get_firstName((person_t*)student)); // get the first name of the person object
    printf("Last Name: %s\n", person_get_lastName((person_t*)student)); // get the last name of the person object
    printf("Age: %d\n", person_get_age((person_t*)student)); // get the age of the person object


    student_dtor(student); // destroy the student object
    free(student); // free the memory allocated for the student object; here because main owns the student object
    return 0;
}