#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>

#define set(x) x = x | 0xFFFF // set all bits of a 16 bit register 
#define clear(x) x = x & 0x0000 // clear all bits of a 16 bit register 
#define set3(x) x = x | 0x3
#define toggle(x) x = ~x

#define setNthBit(x,n) x = x | (0x01<<n)
#define clearNthBit(x,n) x = x & (0 << n)

#define setNbitsAtPosM(x,m,n) x = x | (((1U << n )-1) << m)
#define clearNbitsAtPosM(x,m,n) x = x & ~(((1U << n )-1) << m)

#define setMtoN(x,m,n) x = x | (((1U << (n-m+1))-1) << m)


int main(){

    uint16_t register1 ;

    register1 = 0x0000;

    set3(register1); // set 0 and 1 bits of a register 
    printf("0x%x \n", register1);

    clear(register1);
    set(register1);
    printf("0x%x \n", register1);

    toggle(register1);
    printf("0x%x \n", register1);

    setNthBit(register1,2);
    printf("0x%x \n", register1);

    clearNthBit(register1,2);
    printf("0x%x \n", register1);


    setNbitsAtPosM(register1,2,4);
    printf("0x%x \n", register1);

    clearNbitsAtPosM(register1,2,4);
    printf("0x%x \n", register1);

    setMtoN(register1,3,5);
    printf("0x%x \n", register1);

    
    return 0;
}