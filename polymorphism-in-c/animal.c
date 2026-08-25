
#include <stdio.h>
#include <stdlib.h>
#include"animal.h"



void __animal_sound(struct Animal* animal){
    printf(" Animal: default sound \n");
}

animal_t* newAnimal(){
    return (animal_t*)malloc(sizeof(animal_t));
}

void animal_ctor(animal_t* animal, char* name, int age){
    animal->name = name;
    animal->age = age;
    animal->animal_sound = __animal_sound; 

}

void animal_dtor(animal_t* animal){
    // do nothing
}

void animal_sound(animal_t* animal){ // only base implementation, overriden by derived classes in their own implementation
    animal->animal_sound(animal);
}