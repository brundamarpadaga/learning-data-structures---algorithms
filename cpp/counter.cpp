//Phase 1 (observe the bug): increment a shared counter from two threads without synchronization.
// Print the result — you'll often get less than the expected value because of data races.

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

int counter = 0;
std::mutex mtx; // create a mutex to protect the shared counter

std::atomic<int> atomic_counter(0); // create an atomic counter to protect the shared counter



void increment(){
    for(int i = 0; i < 1000000; ++i){
        std::lock_guard<std::mutex> lock(mtx);
        ++counter; // increment the shared counter variable
        //unlock_guard automatically unlocks the mutex when it goes out of scope, so we don't need to manually unlock it here.
    }
}

void decrement(){
    for(int i = 0; i < 1000000; ++i){
        std::lock_guard<std::mutex> lock(mtx);
        --counter; // decrement the shared counter variable
        //unlock_guard automatically unlocks the mutex when it goes out of scope, so we don't need to manually unlock it here.
    }
}

void increment_a(){
    for(int i = 0; i < 1000000; ++i){
        ++atomic_counter; // increment the shared atomic counter variable
        // No need for explicit locking with std::atomic
    }
}

void decrement_a(){
    for(int i = 0; i < 1000000; ++i){
        --atomic_counter; // decrement the shared atomic counter variable
        // No need for explicit locking with std::atomic
    }
}


int main(){
    // create two threads that increment a shared counter

    

    std::thread thread1(increment);
    std::thread thread2(decrement);

    std::thread thread3(increment_a);
    std::thread thread4(decrement_a);

    // wait for both threads to finish
    thread1.join();
    thread2.join();

    thread3.join();
    thread4.join();

    // print the final value of the counter
    std::cout << "Final counter value: " << counter << std::endl;
    std::cout << "Final atomic counter value: " << atomic_counter.load() << std::endl;



}