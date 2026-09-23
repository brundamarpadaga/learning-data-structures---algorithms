#include"frame_parser.h"
#include<stdio.h>


bool perform_check(frame_parser_t *p){
    uint8_t calc_checksum = 0;
    for(int i = 0; i < p->len; i++){
        calc_checksum ^= p->data[i];
    }
    printf("checksum = 0x%02x, calculated checksum = 0x%02x\n", p->checksum, calc_checksum);
    return calc_checksum == p->checksum;
}

// Feed one byte into the parser.
// Returns true when a complete valid frame has been received.
bool parser_feed(frame_parser_t *p, uint8_t byte){
     
    if(p->state == STATE_WAIT_SYNC){
        if(byte == 0xAA){
            p->state = STATE_WAIT_LEN;
        }
        else{
            printf("Waiting for SYNC, received: 0x%02x\n", byte);
        }
        // otherwise wait for SYNC in the same state
        
    }
    else if( p->state == STATE_WAIT_LEN){
        if(byte == 0 || byte > 64){
            printf("Invalid data length: %d", byte);
            p->state = STATE_WAIT_SYNC; // reset to wait for SYNC
            return false; // return false, parser cannot move forward without valid data length
        }
        p->len = byte;
        printf("Received length: %d, moving to read data state\n", p->len);
        p->state = STATE_READ_DATA;
        p->index = 0;
    }

    else if(p->state == STATE_READ_DATA){
        if( p->index < p->len-1 ) {
            p->data[p->index] = byte;
            printf("Received data byte %d: 0x%02x\n", p->index, p->data[p->index]);
            p->index++;
        }
        else if( p->index == p->len-1 ) {
            p->data[p->index] = byte;
            p->state = STATE_WAIT_CHECKSUM;
        }
        
    }
    else if(p->state == STATE_WAIT_CHECKSUM){
        p->checksum = byte;
        printf("Received checksum: 0x%02x\n", p->checksum);
        if (perform_check(p)){
            p->state = STATE_WAIT_SYNC; // reset to wait for SYNC
            return true;
        }
        else {
            p->state = STATE_WAIT_SYNC; // reset to wait for SYNC
            printf("Checksum mismatch, resetting parser to wait for SYNC\n");
            p->state = STATE_WAIT_SYNC; // reset to wait for SYNC
            return false;
        }
        
    }

    return false; // return false if frame is not complete yet

}


int main(){
    frame_parser_t p = {0};

    parser_feed(&p, 0xA);
    parser_feed(&p, 0xAA);

    parser_feed(&p, 0x1B);

    printf("Feeding data bytes ---\n");
    for(int i = 0; i < 0x1B; i++){
        
        parser_feed(&p, 0xA+i);
    }
    printf("\n Feeding checksum byte ---\n");

    

    printf("Frame parsed %s: %d bytes\n", parser_feed(&p, 0x25)? "successfully":"unsuccessfully", p.len);
    return 0;


}