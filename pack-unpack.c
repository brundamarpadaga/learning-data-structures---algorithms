/* 
/* A LIDAR point is packed into a 32-bit word:
   bits [31:20] — range (12 bits, 0–4095 cm)
   bits [19:12] — intensity (8 bits)
   bits [11:10] — return number (2 bits)
   bits  [9:0]  — channel id (10 bits)

   Implement:

uint32_t pack_point(uint16_t range, uint8_t intensity,
                    uint8_t ret_num, uint16_t channel);

void unpack_point(uint32_t word, uint16_t *range, uint8_t *intensity,
                  uint8_t *ret_num, uint16_t *channel);
Do this first. Then I'll give you the SIMD problem.
*/

#include<stdint.h>
#include<string.h>
#include<stdio.h>
#include <assert.h>

struct point {
    uint16_t range:12; // 31: 20 
    uint8_t intensity:8; // 19:12 
    uint8_t return_number:2; // 11:10
    uint16_t channel_id:10; // 9:0 1010
}__attribute__((packed));


uint32_t pack_point(uint16_t range, uint8_t intensity, uint8_t ret_num, uint16_t channel){

    if( range > 0xFFF){
        range = 4095; // limit to upper bound 
    }

    struct point p1;
    uint32_t result;
    p1.range = range;
    p1.intensity = intensity;
    p1.return_number = ret_num;
    p1.channel_id = channel; // range intensity ret channel

    result = ((p1.range & 0xFFF) << 20) | ((p1.intensity & 0xFF) << 12) | (p1.return_number & 0x3) << 10 | (p1.channel_id & 0x3FF) ; 
    return result;

}

void unpack_point(uint32_t word, uint16_t *range, uint8_t *intensity, uint8_t *ret_num, uint16_t *channel){
    struct point p1 ;
    

    *range = (word >> 20) & 0xFFF;
    *intensity = (word >> 12) & 0xFF;
    *ret_num = (word >> 10) & 0x03;
    *channel = word & 0x3FF ;

}


int main(){

    // Known inputs
    uint16_t range     = 0xABC;   // 12 bits → goes to [31:20]
    uint8_t  intensity = 0x5A;    // 8  bits → goes to [19:12]
    uint8_t  ret_num   = 0x2;     // 2  bits → goes to [11:10]
    uint16_t channel   = 0x155;   // 10 bits → goes to [9:0]

    // Hand-compute expected:
    // 0xABC << 20 = 0xABC00000
    // 0x5A  << 12 = 0x0005A000
    // 0x2   << 10 = 0x00000800
    // 0x155       = 0x00000155
    //            OR= 0xABC5A955
    uint32_t expected = 0xABC5A955;

    uint32_t packed = pack_point(range, intensity, ret_num, channel);
    printf("packed = 0x%08X, expected = 0x%08X\n", packed, expected);
    assert(packed == expected);

    // Round-trip: unpack and verify fields come back unchanged
    uint16_t r; uint8_t inten, ret; uint16_t ch;
    unpack_point(packed, &r, &inten, &ret, &ch);

    assert(r     == range);
    assert(inten == intensity);
    assert(ret   == ret_num);
    assert(ch    == channel);

    // Edge case: range overflow clamps to 0xFFF
    assert(pack_point(0x1FFF, 0, 0, 0) == pack_point(0xFFF, 0, 0, 0));

    printf("all assertions passed\n");

}


