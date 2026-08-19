#ifndef STUDENT_H
#define STUDENT_H

#include "person.h" // the implementation of the base class is hidden from the student class

typedef enum Grade{
    A, A_MINUS, B, B_MINUS, C
} Grade;

typedef struct Student {
    person_t* person; // pointer to the base class (person_t)
    int* studentId;
    Grade grade;
} student_t;

student_t* newStudent();
void student_ctor(student_t* student, char* firstName, char* lastName, int age, int studentId, Grade grade);
void student_dtor(student_t* student);

void printStudent(student_t* student);
int getStudentId(student_t* student);
Grade getStudentGrade(student_t* student);
void setStudentGrade(student_t* student, Grade grade);

#endif // STUDENT_H