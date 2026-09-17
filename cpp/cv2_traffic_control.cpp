/* Problem: Traffic Light Controller
You have an intersection with two roads — North-South and East-West. Cars on each road are separate threads.

Rules:
Only one direction can have a green light at a time
A direction gets green for exactly 5 cars, then switches
Cars must wait at red — they cannot proceed until their light is green
Both directions have 10 cars each to send through
What you need:

shared state:
    current_green = NORTH_SOUTH  (or EAST_WEST)
    cars_passed_this_phase = 0

mutex — protects shared state
condition variable — cars wait on this

north_south thread:
    wait until current_green == NORTH_SOUTH
    pass a car through, increment counter
    if counter hits 5, switch green to EAST_WEST, reset counter, notify

east_west thread:
    wait until current_green == EAST_WEST
    pass a car through...
Expected output (roughly):

NS car 1 passed
NS car 2 passed
NS car 3 passed
NS car 4 passed
NS car 5 passed  ← green switches
EW car 1 passed
EW car 2 passed
...*/

#include<mutex>
#include<iostream>
#include<thread>
#include<condition_variable>



std::mutex mtx;
std::condition_variable cars_passing;
enum current_green {
    NORTH_SOUTH,
    EAST_WEST
};
int cars_passed_this_phase = 0;
int all_cars_passed = 0;

current_green cg1;


void NS_thread(){
    
    while( all_cars_passed < 20){
        std::unique_lock<std::mutex > lock(mtx);
        while(cars_passed_this_phase < 5){
            cars_passing.wait(lock, []{return (cg1 == NORTH_SOUTH);});
            ++cars_passed_this_phase;
            ++all_cars_passed;
            std::cout << "NS: car passed:" << cars_passed_this_phase << std::endl;
        }  

        std::cout << "here" << std::endl;
        
        cars_passed_this_phase = 0;
        cg1 = EAST_WEST;
        lock.unlock();
        cars_passing.notify_all();

    }
    
    
}

void EW_thread(){
    while( all_cars_passed < 20){
        std::unique_lock<std::mutex > lock(mtx);
        while(cars_passed_this_phase < 5 ){
            cars_passing.wait(lock, []{return ( cg1 == EAST_WEST);});

            ++cars_passed_this_phase;
            ++all_cars_passed;
            std::cout << "EW: car passed:" << cars_passed_this_phase << std::endl;

            
        }

        
        cg1 = NORTH_SOUTH;
        cars_passed_this_phase = 0;
        lock.unlock();
        cars_passing.notify_all(); 
    } 

    
}

int main(){

    std::thread ns1(NS_thread);
    std::thread ew1(EW_thread);



    ns1.join();
    ew1.join();
}

