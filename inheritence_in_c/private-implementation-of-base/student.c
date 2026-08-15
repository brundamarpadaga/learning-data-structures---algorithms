#include<stdio.h>
#include<stdlib.h>

#include"student.h"


student_t* newStudent(){
    return (student_t*)malloc(sizeof(student_t));
}
void student_ctor(student_t* student, char* firstName, char* lastName, int age, int studentId, Grade grade){
    person_t *person = newPerson(); // create a new person_t object
    person_ctor(person, firstName, lastName, age); // initialize the person_t object
    student->person = person; // set the pointer to the person_t object
    student->studentId = (int*)malloc(sizeof(int)); // allocate memory for studentId
    *student->studentId = studentId;
    student->grade = grade;
}
void student_dtor(student_t* student){
    free(student->studentId); // free the memory allocated in child object
    person_dtor(student->person); // call the destructor of the parent object
    free(student); // free the child object
}

void printStudent(student_t* student){  
    printf("Student: %s %s, Age: %d, Student ID: %d, Grade: %d\n", 
        person_get_firstName(student->person), 
        person_get_lastName(student->person), 
        person_get_age(student->person), 
        *student->studentId, 
        student->grade);
}
int getStudentId(student_t* student){
    return *student->studentId;
}
Grade getStudentGrade(student_t* student){
    return student->grade;
}
void setStudentGrade(student_t* student, Grade grade){
    student->grade = grade;
}

char* getStudentFirstName(student_t* student){
    return person_get_firstName(student->person);
}
char* getStudentLastName(student_t* student){
    return person_get_lastName(student->person);
}
int getStudentAge(student_t* student){
    return person_get_age(student->person);
}