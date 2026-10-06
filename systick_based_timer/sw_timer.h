#ifndef SW_TIMER_H
#define SW_TIMER_H

#include <stdint.h>
#include <stdbool.h>

#define MAX_TIMERS  4

typedef void (*timer_cb_t)(char* name); // callback function type

typedef struct {
    uint32_t   start_tick; // tick count when timer was started
    uint32_t   period_ms; // timer period in milliseconds
    bool       active; // true if timer is active
    timer_cb_t cb; // callback function to call when timer expires
    bool periodic; // true if timer is periodic
    char* name; // optional name for the timer
    uint32_t index; // current timer allocated, starts from 0
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

// Allocates a timer slot from the pool, returns NULL if full
sw_timer_t* timer_alloc(void);

// Returns a timer slot back to the pool
void timer_free(sw_timer_t *t);

// Polls all active timers in the pool — call once per main loop iteration
void poll_all(void);

// prints the current timer pool
void print_timer_pool();

// Checks if a timer is part of the pool
bool timer_is_part_of_pool(sw_timer_t *t);


#endif // SW_TIMER_H