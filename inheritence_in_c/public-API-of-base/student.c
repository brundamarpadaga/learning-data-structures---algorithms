#include<stdio.h>
#include<stdlib.h>

#include"student.h"
#include"person.h"

typedef struct Student {
    int* studentId;
    person_t* person; // pointer to the base class (person_t)
    Grade grade;
} student_t;

const char* grades[] = {"A", "A-", "B", "B-", "C"};


student_t* newStudent(){
    return (student_t*)malloc(sizeof(student_t));
}
void student_ctor(student_t* student, char* firstName, char* lastName, int age, int studentId, Grade grade){
    
    student->person = newPerson(); // create a new person object and assign it to the student object
    person_ctor(student->person, firstName, lastName, age); // initialize the person_t object
    // student class has no idea about the person_t struct, so we need to cast it to person_t* to access its members
    student->studentId = (int*)malloc(sizeof(int)); // allocate memory for studentId
    *student->studentId = studentId;
    student->grade = grade;
}
void student_dtor(student_t* student){
    free(student->studentId); // free the memory allocated in child object
    person_dtor(student->person); // call the destructor of the parent object
    free(student->person); // free the memory allocated for the person object
    
}

void printStudent(student_t* student){  
    printf("Student: %s %s, Age: %d, Student ID: %d, Grade: %s\n", 
        person_get_firstName(student->person), 
        person_get_lastName(student->person), 
        person_get_age(student->person), 
        *student->studentId, 
        grades[student->grade]);
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