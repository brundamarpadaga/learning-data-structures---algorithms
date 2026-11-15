/*
Problem 1: CRC-16 (CCITT)
RAIL deals with BLE, Zigbee, Thread — every one of them uses CRC for 
packet validation. XOR checksum (what your frame parser used) can't 
detect burst errors. CRC-16 is what actually ships in hardware.

Implement it two ways:


// Bitwise — process each bit with polynomial 0x1021
uint16_t crc16_bitwise(const uint8_t *data, size_t len);

// Table-driven — precompute 256-entry lookup table, then one table
// lookup per byte instead of 8 bit-operations
void     crc16_table_init(uint16_t table[256]);
uint16_t crc16_fast(const uint16_t table[256], const uint8_t *data, size_t len);
Then go back to your frame parser and swap the XOR checksum for CRC-16. 
That's exactly how a real protocol frame would look.

*/

#include <stdint.h>
#include <stdio.h>
#include<time.h>


uint16_t crc16_bitwise(const uint8_t * data, size_t len){

    uint16_t crc = 0xFFFF; // initial register value
    uint16_t poly = 0x1021; // standard polynomial to generate crc
    for(int i = 0; i < len; i++){
        uint8_t byte = data[i];
        crc = crc ^ (byte << 8); // xor with initial crc, byte is shifted left by 8 bits to align with the upper byte of the crc register

        for ( int j = 0; j < 8; j++){ // iterate over each bit in the byte
            if( crc & 0x8000 ){
                crc = (crc << 1) ^ poly;  // if the uppermost bit is set, shift left and xor with polynomial
            }
            else{
                crc = ( crc << 1); // otherwise just shift left
            }
        }

    }
    return crc;

}



// Table-driven — precompute 256-entry lookup table, then one table
// lookup per byte instead of 8 bit-operations
void     crc16_table_init(uint16_t* table){
    uint16_t poly = 0x1021;
    for ( int i = 0; i < 256; i++){ // make a table of 256 entries, one for each possible byte value
       
        uint16_t crc = (i << 8); // crc is initialized to the byte value shifted left by 8 bits, so that it aligns with the upper byte of the crc register

        for ( int j = 0; j < 8; j++){
            if( crc & 0x8000 ){
                crc = (crc << 1) ^ poly; // if the uppermost bit is set, shift left and xor with polynomial
            }
            else{
                crc = ( crc << 1); // otherwise just shift left
            }
        }

        table[i] = crc & 0xFFFF; // store the result in the table, masking to 16 bits
    }
}
uint16_t crc16_fast(const uint16_t* table, const uint8_t *data, size_t len){

    uint16_t crc = 0xFFFF;
    for ( int i = 0 ; i < len; i++){

        uint8_t index = ((crc>>8) ^ data[i]) & 0xFF; // xor with initial crc, crc shifted right by 8 bits to get the upper byte, 
                                                     //  then xor with the data byte, and mask to 8 bits to get the index into the table, 
                                                     //  why? because the table is 256 entries, so we need to get the lower 8 bits of the result to use as an index into the table  
        crc = ((crc<<8) ^ table[index]) & 0xFFFF; // shift crc left by 8 bits, xor with the table entry at the index, and mask to 16 bits to get the new crc value
        
    }
    return crc;
}


int main(){
    size_t size = 9;
    
    uint8_t data[] = "123456789";
    // measure time taken by bitwise implementation
    time_t start = clock();
    printf("crc = %x \n ", crc16_bitwise( data, size));
    time_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken by bitwise implementation: %f seconds\n", time_taken);


    uint16_t table[256] = {0};
    crc16_table_init(table);

    
    time_t start2 = clock();
    printf("crc = %x \n ", crc16_fast(table, data, size));
    time_t end2 = clock();
    double time_taken2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    printf("Time taken by table-driven implementation: %f seconds\n", time_taken2);


    float speed_up = time_taken / time_taken2;
    printf("Speed up: %f times \n", speed_up);
}