#include"RADIO_SM.h"

/* 
Problem 2: Radio Power State Machine
RAIL's core job is managing radio state. Model a simplified radio with these states and legal transitions:


OFF → IDLE → RX
           → TX
      RX   → IDLE (packet received or timeout)
      TX   → IDLE (packet sent)
      any  → OFF

typedef enum { RADIO_OFF, RADIO_IDLE, RADIO_RX, RADIO_TX } radio_state_t;

typedef struct {
    radio_state_t state;
    uint32_t      state_entry_tick;   // tick when current state was entered
    uint32_t      rx_timeout_ms;      // auto-return to IDLE if no packet
} radio_t;

bool radio_transition(radio_t *r, radio_state_t new_state);
bool radio_tick(radio_t *r);   // call each ms — handles RX timeout
const char* radio_state_name(radio_state_t s);
radio_transition should reject illegal transitions (e.g. OFF → TX directly) and return false. 
radio_tick checks if RX has timed out and transitions back to IDLE automatically — this is exactly what RAIL does for receive windows.
*/

#include <stdio.h>
#include <stdbool.h>

volatile uint32_t tick_count = 0;

void sys_tick_isr(){
    tick_count++;
}

uint32_t get_tick_count(){
    return tick_count;
}


bool radio_transition(radio_t *r, radio_state_t new_state){
    if(r->state == RADIO_OFF && new_state ==  RADIO_IDLE){
        r->state = RADIO_IDLE; // switch on and is in idle state
        printf("Radio transitioned from OFF to IDLE state \n");
        return true;
    }

    else if( r->state == RADIO_IDLE && new_state == RADIO_RX){
        
        r->state = RADIO_RX; // switch to RX state
        r->state_entry_tick = get_tick_count(); // record the tick when RX state was entered
        if(radio_tick(r)){ r->state = RADIO_IDLE; printf("Radio transitioned from RX to IDLE state \n");} // call radio_tick to handle RX timeout
        else{ printf("Radio transitioned from IDLE to RX state \n");}
        return true;
        

    }

    else if( r->state == RADIO_IDLE && new_state == RADIO_TX){
        r->state = RADIO_TX; // switch to TX state
        printf("Radio transitioned from IDLE to TX state \n");
        return true;
    }
    else if( r->state == RADIO_RX && new_state == RADIO_IDLE){
        r->state = RADIO_IDLE; // switch to IDLE state after RX
        printf("Radio transitioned from RX to IDLE state \n");
        return true;
    }

    else if( r->state == RADIO_TX && new_state == RADIO_IDLE){
        r->state = RADIO_IDLE; // switch to IDLE state after TX
        printf("Radio transitioned from TX to IDLE state \n");
        return true;
    }

    else if( new_state == RADIO_OFF){
        r->state = RADIO_OFF; // switch off from any state
        printf("Radio transitioned to OFF state \n");
        return true;
    }
    
    else{
        return false; // illegal transition

    }



}
bool radio_tick(radio_t *r){  // call each ms — handles RX timeout
    if(r->state == RADIO_RX && (get_tick_count() - r->state_entry_tick) >= r->rx_timeout_ms){
        printf("RX timeout occurred \n");
        return true; // RX timeout occurred, transition back to IDLE state
    }
    return false; // No timeout occurred
}
const char* radio_state_name(radio_state_t s){
    return (s == RADIO_OFF) ? "OFF" : (s == RADIO_IDLE) ? "IDLE" : (s == RADIO_RX) ? "RX" : (s == RADIO_TX) ? "TX" : "UNKNOWN";
}

void main(){
    radio_t radio = {RADIO_OFF, 0, 1000}; // initialize radio in OFF state with RX timeout of 1000 ms

    radio_transition(&radio, RADIO_IDLE); // transition to IDLE state
    radio_transition(&radio, RADIO_RX); // transition to RX state
    while(1){
        sys_tick_isr(); // simulate system tick
        

        
        if(radio_tick(&radio)) {// check for RX timeout
            radio_transition(&radio, RADIO_IDLE); // transition back to IDLE state if RX timeout occurred
        }
        radio_transition(&radio, RADIO_TX); // transition to TX state
        
        


        
    }
}