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
void radio_tick(radio_t *r);   // call each ms — handles RX timeout
const char* radio_state_name(radio_state_t s);
radio_transition should reject illegal transitions (e.g. OFF → TX directly) and return false. 
radio_tick checks if RX has timed out and transitions back to IDLE automatically — this is exactly what RAIL does for receive windows.
*/

uint32_t tick_count = 0;

void sys_tick_isr(){
    tick_count++;
}

uint32_t get_tick_count(){
    return tick_count;
}


bool radio_transition(radio_t *r, radio_state_t new_state){
    if(r->state == RADIO_OFF && new_state ==  RADIO_IDLE){
        r->state = RADIO_IDLE; // switch on and is in idle state
    }

    else if( r->state == RADIO_IDLE && new_state == RADIO_RX){
        r->state = RADIO_RX;

    }
    


}
void radio_tick(radio_t *r){  // call each ms — handles RX timeout


} 
const char* radio_state_name(radio_state_t s){

}