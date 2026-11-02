/*
vector of 1,000,000 integers (fill with 1s for easy verification)

split into 4 equal chunks:
    chunk 0: indices 0       to 249,999
    chunk 1: indices 250,000 to 499,999
    chunk 2: indices 500,000 to 749,999
    chunk 3: indices 750,000 to 999,999

launch 4 tasks with std::async, each sums its chunk
collect all 4 results with .get()
add them together in main

*/

#include <iostream>
#include <vector>
#include <future>

int sum_chunk(const std::vector<int>& data, size_t start, size_t end) {
    
    int result = 0;
    for (size_t i = start; i < end; ++i) {
        result += data[i];
    }
    return result;
    
}

int main(){

    const int data_size = 1000000;
    std::vector<int> vec(data_size, 1);

    int chunk = data_size / 4;

    std::future<int> f1 = std::async(std::launch::async, sum_chunk, std::ref(vec), 0, chunk);
    std::future<int> f2 = std::async(std::launch::async, sum_chunk, std::ref(vec), chunk, 2*chunk);
    std::future<int> f3 = std::async(std::launch::async, sum_chunk, std::ref(vec), 2*chunk, 3*chunk);
    std::future<int> f4 = std::async(std::launch::async, sum_chunk, std::ref(vec), 3*chunk, 4*chunk);

    // all threads are running simultaneously now

    int total =  f1.get() + f2.get() + f3.get() + f4.get() ;
    
    std::cout << "Total = " << total << std::endl;
}