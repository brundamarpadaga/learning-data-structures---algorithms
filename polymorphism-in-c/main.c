/* Understanding Polymorphism in C , code taken from the book Extreme C by Kamran Amini*/

#include<stdio.h>
#include<stdlib.h>
#include"animal.h"
#include"tiger.h"

int main(){
    animal_t* animal = newAnimal();
    tiger_t* tiger = newTiger();
    animal_ctor(animal, "Generic Animal", 5);
    tiger_ctor(tiger, "Tiger", 3);
    animal_sound(animal); // should print "Animal: default sound"
    animal_sound((animal_t*)tiger); // should print "RAWRRR"

    // Clean up
    animal_dtor(animal);
    tiger_dtor(tiger);
    free(animal);
    free(tiger);
}
