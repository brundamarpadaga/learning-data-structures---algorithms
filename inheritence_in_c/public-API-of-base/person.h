#ifndef PERSON_H
#define PERSON_H

// this is the public API of the base class person_t; 
// it is used to define the interface of the person_t struct; 
// consists of member variables and methods of the person_t struct;

typedef struct person_t person_t; // forward declaration of person_t struct

person_t* newPerson();
void person_ctor(person_t* person, char* firstName, char* lastName, int age);
void person_dtor(person_t* person);

char* person_get_firstName(person_t* person);
char* person_get_lastName(person_t* person);
int person_get_age(person_t* person);



#endif // PERSON_H