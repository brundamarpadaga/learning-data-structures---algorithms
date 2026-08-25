#ifndef TIGER_H
#define TIGER_H

#include"animal.h"

typedef struct Tiger{
    animal_t animal;
} tiger_t;

tiger_t* newTiger();
void tiger_ctor(tiger_t* tiger, char* name, int age);
void tiger_dtor(tiger_t* tiger);

#endif