#include"tiger.h"

tiger_t* newTiger(){
    return (tiger_t*)(malloc(sizeof(tiger_t)));
}

void __tiger_sound(animal_t* animal){
    printf(" RAWRRR \n");
}

void tiger_ctor(tiger_t* tiger,char* name,int age){
    animal_t* animal_ptr = (animal_t*)tiger;
    animal_ptr->age = age;
    animal_ptr->name = name;
    animal_ptr->animal_sound = __tiger_sound; // overriding

}
void tiger_dtor(tiger_t* tiger){
    //do nothing
}

