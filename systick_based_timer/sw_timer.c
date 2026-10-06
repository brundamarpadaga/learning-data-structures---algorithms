
#include"sw_timer.h"
#include<stdio.h>
#include<unistd.h> // for sleep function

//new feature : poll_all_timers() function to poll all timers in an array

sw_timer_t timers[MAX_TIMERS];

volatile uint32_t tick_count = 0; // global tick count

// Simulated ISR — call this in a loop to simulate 1ms ticks
void systick_isr(void){
    tick_count++;
}

// Returns current tick count
uint32_t get_tick(void){
    return tick_count;
}

// Returns ms elapsed since a snapshot tick
uint32_t elapsed_ms(uint32_t since){
    return tick_count-since; // this many ms has passed from "since"
}

// Blocking delay
void delay_ms(uint32_t ms){
    uint32_t current = get_tick();
    while( elapsed_ms(current) <  ms){ 
        systick_isr(); // keep incrementing ticks
        usleep(1000); // sleep for 1 millisecond
    }
}

// Arms a one-shot timer with a callback
void timer_start(sw_timer_t *t,char* name, uint32_t period_ms, timer_cb_t cb, bool periodic){
    t->period_ms = period_ms;
    t->cb = cb;
    t->start_tick = get_tick();
    t->active = 1;
    t->periodic = periodic;
    t->name = name;
    printf("Timer started \n");
}

// Allocates a timer slot from the pool, returns NULL if full
sw_timer_t* timer_alloc(void){
    
}

// Returns a timer slot back to the pool
void timer_free(sw_timer_t *t);

// Polls all active timers in the pool — call once per main loop iteration
void poll_all(void);


// Call from main loop — fires callback if timer has expired
void timer_poll(sw_timer_t *t){
    if(elapsed_ms(t->start_tick) >= t->period_ms && t->active){
        t->cb(t->name); // call the callback function
        if(t->periodic){
            t->start_tick = get_tick(); // reset for periodic timer
        } else {
            t->active = 0; // deactivate one-shot timer
        }
    }

}

void print(char *name){
    printf("Tick: %d, %s went off \n", get_tick(), name);
}

int main(){
    
    sw_timer_t* timer1 = timer_alloc();
    sw_timer_t* timer2;

    timer_start(&timers[0], "timer1",10, print, true);
    timer_start(&timers[1], "timer2", 5, print, true);
    while(1){
        sleep(1); // sleep for 1 second
        systick_isr();
        timer_poll(&timer1);
        timer_poll(&timer2);

    }
    
}