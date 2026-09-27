
#include"sw_timer.h"
#include<stdio.h>
#include<unistd.h> // for sleep function

volatile int tick_count = 0; // global tick count

// Simulated ISR — call this in a loop to simulate 1ms ticks
void systick_isr(void){
    sleep(1); // simulate 1ms tick
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
    }
}

// Arms a one-shot timer with a callback
void timer_start(sw_timer_t *t, uint32_t period_ms, timer_cb_t cb){
    t->period_ms = period_ms;
    t->cb = cb;
    t->start_tick = get_tick();
    t->active = 1;
}

// Call from main loop — fires callback if timer has expired
void timer_poll(sw_timer_t *t){
    if(elapsed_ms(t->start_tick) >= t->period_ms && t->active){
        t->cb();
        t->active = 0;
    }

}

void print(){
    printf("timer went off");
}

int main(){
    sw_timer_t my_timer;
    timer_start(&my_timer, 10000, print);
    while(1){
        systick_isr();
        timer_poll(&my_timer);

    }
    
}