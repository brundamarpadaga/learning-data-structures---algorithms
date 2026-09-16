/* Producer/Consumer queue
One thread produces work, another consumes it. 
Teaches condition_variable + mutex together. 
The classic real-world pattern (message queues, thread pools).

Readers-Writers lock
Multiple threads can read simultaneously, but a writer gets exclusive access. 
Teaches std::shared_mutex (C++17) and the tradeoff between read throughput and write fairness.*/

#include<iostream>
#include<mutex>
#include<queue>
#include<random>
#include<thread>
#include<condition_variable>
#include<chrono>


std::mutex mtx;
std::queue<int> queue1;
std::condition_variable queue_not_full;
std::condition_variable queue_full;

void producer(){

    //generate an item and push them onto queue
    std::random_device rd;
    
    // 2. Initialize the standard Mersenne Twister engine with the seed
    std::mt19937 gen(rd());
    
    // 3. Define the range (inclusive, e.g., 1 to 100)
    std::uniform_int_distribution<int> distr(1, 100);

    for(int i = 0; i < 20; i++){
        // 4. Generate the random number
        int random_num = distr(gen);

        std::unique_lock<std::mutex> lck(mtx);
        // queue_not_full gets triggered when it gets notified, how does this work? -> it will check the condition in the lambda function, if it is true, it will wake up and continue execution, if it is false, it will go back to sleep and wait for the next notification
        // and lck is used to lock the mutex, so that only one thread can access the queue at a time, and it will be unlocked when the lock goes out of scope
        queue_not_full.wait(lck, [] {return (queue1.size()<5);} ); // wake up when size is less than 5 -> while(size>=5) wait 

        std::cout << "Producer side: " << random_num << std::endl;

        queue1.push(random_num);
        lck.unlock();

        queue_full.notify_one(); // notify the consumer that there is an item in the queue
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
    }



}

void consumer(){

    for(int i = 0; i < 20; i++){
        std::unique_lock<std::mutex> lck(mtx);
        queue_full.wait(lck, []{return !queue1.empty(); }); // wake when queue is not empty

        std::cout << "Consumer side: " << queue1.front() << std::endl;
        queue1.pop();

        lck.unlock();
        queue_not_full.notify_one(); // notify the producer that there is space in the queue
        std::this_thread::sleep_for(std::chrono::milliseconds(150)); 
    }


}


int main(){

    std::thread consumer_t(consumer);
    std::thread producer_t(producer);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    consumer_t.join();
    producer_t.join();

    return 0;

}