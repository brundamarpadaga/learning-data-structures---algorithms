#ifndef ANIMAL_H
#define ANIMAL_H


typedef struct Animal {
    char* name;
    int age;
    void (*animal_sound)(struct Animal*); // function pointer for the speak method, overriden by derived classes
} animal_t;

animal_t* newAnimal();
void animal_ctor(animal_t* animal, char* name, int age);
void animal_dtor(animal_t* animal);
void animal_sound(animal_t* animal);



#endif // ANIMAL_H