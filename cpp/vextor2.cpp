#include<iostream>
#include<vector>
#include<unordered_map>

// Write a function that takes a vector<int> and returns an unordered_map<int,int> 
//counting how many times each value appears. Just the function, don't worry about main().

std::unordered_map<int, int> countOccurences( const std::vector<int>& vec) {
    std::unordered_map<int, int> counts;
    for(int num : vec){
        counts[num] += 1;
    }

    return counts;
}


