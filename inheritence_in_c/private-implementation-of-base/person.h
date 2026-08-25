#ifndef PERSON_H
#define PERSON_H

#include "person_p.h" // is it necessary to include the private implementation of the base class here? Yes, because we need to know the size of the struct person_t in order to allocate memory for it in newPerson() function. The private implementation of the base class is hidden from the student class, but we still need to know its size in order to allocate memory for it.

typedef struct person_t person_t;

person_t* newPerson();
void person_ctor(person_t* person, char* firstName, char* lastName, int age);
void person_dtor(person_t* person);

char* person_get_firstName(person_t* person);
char* person_get_lastName(person_t* person);
int person_get_age(person_t* person);

#endif // PERSON_H