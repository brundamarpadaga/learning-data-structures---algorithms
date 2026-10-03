#include<stdio.h>
#include<stdint.h>



int main(){


    uint32_t num = 0x12345678; // Example number

    uint8_t bytes[4];

    for( int i = 0; i < 4 ; i++){ 
        bytes[3-i] = (num >> ((i)*8))& (0xFF);
    }

    printf("0x%02x ", *(uint32_t*)bytes);

    return 0;


}