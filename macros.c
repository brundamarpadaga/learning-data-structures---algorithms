#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>

#define set(x) x = x | 0xFFFF // set all bits of a 16 bit register 
#define clear(x) x = x & 0x0000 // clear all bits of a 16 bit register 
#define set3(x) x = x | 0x3
#define toggle(x) x = x ^ 0xFFFF // toggle all bits of a 16 bit register

#define setNthBit(x,n) x = x | (0x01<<n)
#define clearNthBit(x,n) x = x & (0 << n)

#define setNbitsAtPosM(x,m,n) x = x | (((1U << n )-1) << m)
#define clearNbitsAtPosM(x,m,n) x = x & ~(((1U << n )-1) << m)

#define setMtoN(x,m,n) x = x | (((1U << (n-m+1))-1) << m)
#define toggleMtoN(x,m,n) x = x ^ (((1U << (n-m+1))-1) << m) //xor to toggle bits from m to n

#define checkNthBit(x,n) x & ( 0x01 << n )

#define checkIfEven(x) !(x & 0x01) // check if a number is even (returns non zero if even)
#define checkIfOdd(x) x & 0x01 // check if a number is odd (returns non zero if odd)

#define checkIfOpSigns(reg1,reg2) ((reg1 >> 15 & 0x01) ^ ((reg2>>15)&0x01)) // non-zero if registers have opposite signs



int main(){

    uint16_t register1 ;
    int16_t register2 = 96;

    register1 = 0x0000;

    set3(register1); // set 0 and 1 bits of a register 
    printf("Set 0 and 1 bits of a register : 0x%x \n", register1);

    clear(register1);
    printf("Clear all bits of a register : 0x%x \n", register1);
    set(register1);
    printf("Set all bits of a register : 0x%x \n", register1);

    toggle(register1);
    printf("Toggle all bits of a register : 0x%x \n", register1);

    setNthBit(register1,2);
    printf("Set 2nd bit of a register : 0x%x \n", register1);

    clearNthBit(register1,2);
    printf("Clear 2nd bit of a register : 0x%x \n", register1);


    setNbitsAtPosM(register1,2,4);
    printf("Set 4 bits starting from position 2 of a register : 0x%x \n", register1);

    clearNbitsAtPosM(register1,2,4);
    printf("Clear 4 bits starting from position 2 of a register : 0x%x \n", register1);

    setMtoN(register1,3,5);
    printf("Set bits from position 3 to 5 of a register : 0x%x \n", register1);

    toggle(register1);
    printf("Toggle all bits : 0x%x \n", register1);

    toggleMtoN(register1,3,5);
    printf("Toggle bits from position 3 to 5 of a register : 0x%x \n", register1);

    uint16_t temp = checkNthBit(register1,4);
    printf("Check if 4th bit is set : %s \n",  temp ? "Yes":"No"); // check if 4th bit is set (returns non zero if set)

    register1 = 32;
    printf("reg1 sign bit: %x\n", (register1 >> 15) & 0x01);
    printf("reg2 sign bit: %x\n", (register2 >> 15) & 0x01);
    printf("register2 = 0x%x \n", register2);
    printf("Check if reg1 and reg2 have opposite signs: %s %x \n", checkIfOpSigns(register1,register2)?"Yes":"No", checkIfOpSigns(register1,register2));


    

    return 0;
}