#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include <assert.h>

/*15-minute step (change_endianness.c): remove the pointer cast. 
The line printf(\"0x%02x \", *(uint32_t*)bytes); reads a uint8_t array through a uint32_t pointer,
 which is undefined behaviour (strict aliasing/alignment).
 Replace it with uint32_t out; memcpy(&out, bytes, 4); and print out with %08x (add #include <string.h>), 
 then wrap the swap in a uint32_t swap32(uint32_t) function and assert swap32(0x12345678) == 0x78563412. 
 Commit, push.*/


 /*15-minute step (change_endianness.c): finish the swap32 function. 
 Move the shift/mask loop out of main into uint32_t swap32(uint32_t v) (return the reversed value), 
 #include <assert.h>, and add assert(swap32(0x12345678) == 0x78563412); assert(swap32(0) == 0); 
 assert(swap32(0xFFFFFFFF) == 0xFFFFFFFF); in main. 
 Commit, push.*/



uint32_t swap32(uint32_t num){

    uint32_t out;
    uint8_t bytes[4];

    for( int i = 0; i < 4 ; i++){ 
        bytes[3-i] = (num >> ((i)*8))& (0xFF);
    }

    memcpy(&out, bytes, 4); // destination, source, number of bytes

    return out;

}

int main(){


    uint32_t num = 0x12345678; // Example number 

    printf("0x%08x ", swap32(num));
    assert(swap32(0xFFFF0FFF) == 0xFF0FFFFF);

    return 0;


}