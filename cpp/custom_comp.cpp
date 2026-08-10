/* sort() with custom comparator

Write a function that takes a vector<pair<int,string>> and sorts it by the int descending, breaking ties alphabetically by string ascending. Return the sorted vector.

Use std::sort with a lambda comparator.


Input:  {{3,"banana"}, {1,"apple"}, {3,"apple"}, {2,"cherry"}}
Output: {{3,"apple"}, {3,"banana"}, {2,"cherry"}, {1,"apple"}} */


#include<iostream>
#include<vector>
#include<algorithm>


std::vector<std::pair<int,std::string>> sort (std::vector<std::pair<int,std::string>> input){

    struct{
        bool operator()(const std::pair<int,std::string>& a, const std::pair<int,std::string>& b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            else{
                return a.first > b.first;

            }
        }
    } customComparator;


    
    std::sort(input.begin(), input.end(), customComparator);
    

    return input;
}




int main(){

    
    std::vector<std::pair<int,std::string>> input = {{3,"banana"}, {1,"apple"}, {3,"apple"}, {2,"cherry"}};
    std::vector<std::pair<int,std::string>> output = sort(input);

    for(const auto& p : output){
        std::cout << "{" << p.first << ",\"" << p.second << "\"}" << std::endl;
    }

    return 0;

}