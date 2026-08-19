#ifndef PERSON_H
#define PERSON_H

#include "person_p.h"

typedef struct person_t person_t;

person_t* newPerson();
void person_ctor(person_t* person, char* firstName, char* lastName, int age);
void person_dtor(person_t* person);

char* person_get_firstName(person_t* person);
char* person_get_lastName(person_t* person);
int person_get_age(person_t* person);

#endif // PERSON_H