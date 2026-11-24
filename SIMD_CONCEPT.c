/* LIDAR intensity clamp
   Given 1024 intensity readings (uint8_t), clamp any value
   above 200 down to 200. Values below 200 stay unchanged.
   
   scalar version first: */

#include<stdint.h>
#include<stdio.h>
#include <arm_neon.h>


void clamp_intensity(uint8_t *data, int len, uint8_t max_val) {

    for( int i = 0; i < len; i++){
        if(data[i] > max_val){
            data[i] = max_val;
        }
    }
    
}


void clamp_intensity_simd(uint8_t *data, int len, uint8_t max_val){

    for(int i = 0)
}


int main(){

    uint8_t intensity[1024];

    // fill the array with some test values
    for(int i = 0; i < 1024; i++){
        intensity[i] = i % 256; // values from 0 to 255
    }

    // clamp the intensity values to a maximum of 200
    clamp_intensity(intensity, 1024, 200);
    printf("Clamped intensity values:\n");
    for(int i = 0; i < 1024; i++){  
        printf("%d ", intensity[i]);
    }

}