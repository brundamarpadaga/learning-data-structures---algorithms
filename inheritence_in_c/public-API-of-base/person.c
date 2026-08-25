#include"person.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct person_t {
    char* firstName;
    char* lastName;
    int age;
} person_t;

person_t* newPerson(){
    return (person_t*)malloc(sizeof(person_t));
}
void person_ctor(person_t* person, char* firstName, char* lastName, int age){
    person->firstName = firstName;
    person->lastName = lastName;
    person->age = age;
}
void person_dtor(person_t* person){
    // do nothing;
}

char* person_get_firstName(person_t* person){
    return person->firstName;
}
char* person_get_lastName(person_t* person){
    return person->lastName;
}
int person_get_age(person_t* person){
    return person->age;
}


