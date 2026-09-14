//Phase 1 (observe the bug): increment a shared counter from two threads without synchronization.
// Print the result — you'll often get less than the expected value because of data races.

#include <iostream>
#include <thread>
#include <mutex>
int counter = 0;
std::mutex mtx; // create a mutex to protect the shared counter

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


int main(){
    // create two threads that increment a shared counter

    

    std::thread thread1(increment);
    std::thread thread2(decrement);

    // wait for both threads to finish
    thread1.join();
    thread2.join();

    // print the final value of the counter
    std::cout << "Final counter value: " << counter << std::endl;



}