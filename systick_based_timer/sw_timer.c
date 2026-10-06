
#include"sw_timer.h"
#include<stdio.h>
#include<unistd.h> // for sleep function

//new feature : poll_all_timers() function to poll all timers in an array

sw_timer_t timers[MAX_TIMERS];
uint8_t timer_index = 0;

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
    printf("%s started \n", name);
}

bool is_timer_active(sw_timer_t *t){
    return t->active;
}

// Allocates a timer slot from the pool, returns NULL if full
sw_timer_t* timer_alloc(void){
    if(timer_index < MAX_TIMERS){
        
        timers[timer_index].index = timer_index;
        timer_index++;
        return &timers[timer_index - 1];
    }
    else{
        printf("Timer pool full, cannot allocate more timers \n");
        return NULL;
    }   
}

bool timer_is_part_of_pool(sw_timer_t *t){
    for(int i = 0; i < timer_index; i++){
        if(&timers[i] == t){
            return true;
        }
    }
    return false;
}

// Returns a timer slot back to the pool
void timer_free(sw_timer_t *t){
    // check if timer is part of the pool
    if( !timer_is_part_of_pool(t) ){ 
        printf("Timer not part of the pool, cannot free \n");
        return;
    }
    
    int index = t->index;
    //sw_timer_t iter = timers[0];
    t->active = 0; // deactivate the timer
    printf("Timer %s freed \n", t->name);
    t->cb = NULL; // clear the callback
    t->periodic = 0; // clear the periodic flag
    t->index = 999; // clear the index
    t->name = NULL; // clear the timer name
    t->period_ms = 0;
    while(index < timer_index - 1){
        timers[index] = timers[index + 1];
        index++;
    }
    timer_index--;

    print_timer_pool(); // print the current timer pool
    
    
}

// Polls all active timers in the pool — call once per main loop iteration
void poll_all(void){
    for(int i = 0; i < timer_index; i++){
        timer_poll(&timers[i]);
    }
}


// Call from main loop — fires callback if timer has expired
void timer_poll(sw_timer_t *t){
    if(elapsed_ms(t->start_tick) >= t->period_ms && t->active){
        t->cb(t->name); // call the callback function
        if(t->periodic){
            t->start_tick = get_tick(); // reset for periodic timer
        } else {
            timer_free(t); // free one-shot timer
        }
    }

}

void print(char *name){
    printf("Tick: %d, %s went off \n", get_tick(), name);
}

void print_timer_pool(){
    printf("Current timer pool: \n");
    for(int i = 0; i < timer_index; i++){
        printf("timer pool index: %d Timer %d: %s, period: %d ms, active: %d, periodic: %d \n", 
            i, timers[i].index, timers[i].name, timers[i].period_ms, timers[i].active, timers[i].periodic);
    }
}

int main(){
    
    sw_timer_t* timer1 = timer_alloc();
    sw_timer_t* timer2 = timer_alloc();
    sw_timer_t* timer3 = timer_alloc();
    sw_timer_t* timer4 = timer_alloc();

    timer_start(timer1, "timer1",10, print, false);
    timer_start(timer2, "timer2", 5, print, false);
    timer_start(timer3, "timer3", 15, print, false);
    timer_start(timer4, "timer4", 20, print, false);
    while(timer_index > 0){
        sleep(1); // sleep for 1 second
        systick_isr();
        poll_all(); // poll all timers
        
        

    }
    
}