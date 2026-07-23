#include <chrono>
#include <iostream>
#include <thread>

void worker(int *val) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "worker sees: " << *val << '\n';
}

//advantage of heap is that it avoids dangling pointer issues when the stack frame of spawn_task is gone
// variable can live on the heap until it is explicitly deleted
// but it could be deleted before the thread is done using it, so we need to be careful about that
// HEAP DID NOT solve the dangling pointer issue, it just moved it to a different place in memory. The thread may still access the memory after it has been deleted, 
// leading to undefined behavior. A better approach would be to use smart pointers (like std::shared_ptr) to manage the lifetime of the object automatically.
void spawn_task(void) {
    int value = 42;  // lives on spawn_task's stack frame
    int *ptr = new int(value); // allocate on heap to avoid dangling pointer              
    std::thread t(worker, ptr); // passing &value "outward"
    if (t.joinable()) {
        t.join(); // wait for the thread to finish before deleting the pointer
    }
    delete ptr;                    // clean up the allocated memory


    t.detach();                    // spawn_task returns immediately
}                                  // value's stack frame is now gone

int main(void) {
    spawn_task();
    std::this_thread::sleep_for(std::chrono::seconds(4));
    return 0;
}