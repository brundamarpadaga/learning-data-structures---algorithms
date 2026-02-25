#include<stdio.h>
#include<string.h>
#include<stddef.h>
#include<stdint.h>


typedef struct details{
    int id;
    char name[30];
    int age;
}details_t;

typedef struct controlReg{
    uint16_t enable:1; 
    uint16_t mode:3;
    uint16_t reserved:12;
}controlReg_t;

struct packet  {
    uint8_t ID; // 1 byte
    uint32_t timestamp; // 4 bytes
    uint16_t value; //2 bytes
}__attribute__((packed)); // telling the compiler not to insert padding bytes

int main(){

    details_t person1;
    controlReg_t controlReg1;
    struct packet packet1;
    controlReg1.enable = 1;
    controlReg1.mode = 3; // 011
    person1.id = 1;
    strcpy(person1.name, "John");
    person1.age = 25;


    printf( "Size: %zu \n", sizeof(person1)); // 4+30+4 ( 2 bytes for padding)
    printf("offset of age: %zu \n", offsetof(details_t, age));

    printf("Vaue of controlReg: %d \n", *(uint16_t*)&controlReg1);
    printf("size of controlreg1 : %zu \n",sizeof(controlReg1)); // 

    printf("size of packet1 : %zu \n",sizeof(packet1)); // size = 12 if __attribute__((packed)) not used 
    
    return 0;
}