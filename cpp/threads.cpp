#include <chrono>
#include <iostream>
#include <thread>

void worker(int *val) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "worker sees: " << *val << '\n';
}

void spawn_task(void) {
    int value = 42;  // lives on spawn_task's stack frame
    int *ptr = &value;               
    std::thread t(worker, ptr); // passing &value "outward"
    t.detach();                    // spawn_task returns immediately
}                                  // value's stack frame is now gone

int main(void) {
    spawn_task();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}