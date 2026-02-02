#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

typedef struct student{
        char name[50];
        int age;
        float gpa;
    } student_t;

void printStudent(student_t* stu);
void printArray( int* arr, int size);
void updateElement( int a, int value);
void updateElementByRef( int* a, int value);
int addElementsInArray(int* arr, int size);

#endif // DATASTRUCTURES_H