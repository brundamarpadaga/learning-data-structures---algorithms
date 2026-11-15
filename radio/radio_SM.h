

#ifndef RADIO_SM_H
#define RADIO_SM_H

#include<stdint.h>
#include<stdbool.h>


typedef enum { RADIO_OFF, RADIO_IDLE, RADIO_RX, RADIO_TX } radio_state_t;

typedef struct {
    radio_state_t state;
    uint32_t      state_entry_tick;   // tick when current state was entered
    uint32_t      rx_timeout_ms;      // auto-return to IDLE if no packet
} radio_t;

bool radio_transition(radio_t *r, radio_state_t new_state);
bool radio_tick(radio_t *r);   // call each ms — handles RX timeout
const char* radio_state_name(radio_state_t s);


#endif