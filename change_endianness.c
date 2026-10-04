#include<stdio.h>
#include<stdint.h>
#include<string.h>

/*15-minute step (change_endianness.c): remove the pointer cast. 
The line printf(\"0x%02x \", *(uint32_t*)bytes); reads a uint8_t array through a uint32_t pointer,
 which is undefined behaviour (strict aliasing/alignment).
 Replace it with uint32_t out; memcpy(&out, bytes, 4); and print out with %08x (add #include <string.h>), 
 then wrap the swap in a uint32_t swap32(uint32_t) function and assert swap32(0x12345678) == 0x78563412. 
 Commit, push.*/


int main(){


    uint32_t num = 0x12345678; // Example number

    uint8_t bytes[4];
    uint32_t out;



    for( int i = 0; i < 4 ; i++){ 
        bytes[3-i] = (num >> ((i)*8))& (0xFF);
    }

    memcpy(&out, bytes, 4); // destination, source, number of bytes

    printf("0x%08x ", out);

    return 0;


}