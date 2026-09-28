#ifndef SW_TIMER_H
#define SW_TIMER_H

#include <stdint.h>
#include <stdbool.h>

#define MAX_TIMERS  8

typedef void (*timer_cb_t)(char* name); // callback function type

typedef struct {
    uint32_t   start_tick; // tick count when timer was started
    uint32_t   period_ms; // timer period in milliseconds
    bool       active; // true if timer is active
    timer_cb_t cb; // callback function to call when timer expires
    bool periodic; // true if timer is periodic
    char* name; // optional name for the timer
} sw_timer_t;


// Simulated ISR — call this in a loop to simulate 1ms ticks
void systick_isr(void);

// Returns current tick count
uint32_t get_tick(void);

// Returns ms elapsed since a snapshot tick
uint32_t elapsed_ms(uint32_t since);

// Blocking delay
void delay_ms(uint32_t ms);

// Arms a one-shot timer with a callback
void timer_start(sw_timer_t *t, char* name, uint32_t period_ms, timer_cb_t cb, bool periodic);

// Call from main loop — fires callback if timer has expired
void timer_poll(sw_timer_t *t);

#endif // SW_TIMER_H