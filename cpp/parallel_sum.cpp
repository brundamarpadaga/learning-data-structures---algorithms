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
#include <cassert>

int sum_chunk(const std::vector<int>& data, size_t start, size_t end) {
    
    int result = 0;
    for (size_t i = start; i < end; ++i) {
        result += data[i];
    }
    return result;
    
}

int main(){

    const int data_size = 1000000; // 
    std::vector<int> vec(data_size, 1);

    int num_threads = 3;
    int chunk = data_size / num_threads; //  250,000

    std::vector<std::future<int>> funcs (num_threads);

    std::cout << "here " << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for(int i = 0; i < num_threads; i++){
        size_t start = i * chunk; // 0 250000 500,000 750,000
        size_t end = i == num_threads - 1 ? data_size : start + chunk; // 250,000 500,000 750,000 1,000,000
        std::cout << "start = " << start << " end = " << end << std::endl;
        funcs[i] = std::async(std::launch::async, sum_chunk, std::ref(vec), start, end);
    }
    // all threads are running simultaneously now
    int total =  0;
    for( int i = 0; i < num_threads; i++ ){
        total += funcs[i].get();
    }

    assert(total == data_size); // verify the result is correct

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();   
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "Time taken by parallel execution: " << time_span.count() << " ms" << std::endl;
    


    
    // time taken for single thread sum

    std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
    int total2 = 0;
    for (size_t i = 0; i < data_size; ++i) {
        total2 += vec[i];
    }

    assert(total2 == data_size); // verify the result is correct
    std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
    auto time_span2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2);
    std::cout << "Time taken (single thread): " << time_span2.count() << " ms" << std::endl;



    
    
    std::cout << "Total = " << total << std::endl;
}