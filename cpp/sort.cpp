// Takes a vector<pair<int,int>> where each pair is {start_time, job_id}. Returns the job IDs in a vector<int>,
// ordered by earliest start time (min-heap by first element). Use priority_queue, not sort

#include<iostream>
#include<vector>
#include<queue>

std::vector<int> sort(std::vector<std::pair<int,int>> input){

    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;

    for(auto pair : input){
        pq.push(pair);
    }

    std::vector<int> result;

    while(!pq.empty()){
        result.push_back(pq.top().second);
        pq.pop();
        
    }
    return result;
}


int main(){
    std::vector<std::pair<int,int>> jobs = { {123,12324}, {124,00}, {120,21345} };

    std::vector<int> result = sort(jobs);

    std::cout << result[0] << std::endl;
    std::cout << result[1] << std::endl;
    std::cout << result[2] << std::endl;

    return 0;

}