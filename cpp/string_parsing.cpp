//Exercise 3 (preview — do after 2)
//Parse a line like "42,finish_job,100" into three parts: an int, a string, and an int.
// Use stringstream and getline with a delimiter.

#include<iostream>
#include<sstream>
#include<tuple>
#include<vector>


std::tuple<int,std::string, int> parser( std::string line){
    std::stringstream stream(line);
    std::vector<std::string> tokens ;
    std::string token;

    while(std::getline(stream, token, ',')){
        
        tokens.push_back(token);     
    
    }

    std::tuple<int,std::string,int> result;
    
    result = std::make_tuple(std::stoi(tokens[0]), tokens[1], std::stoi(tokens[2]));
    
    return result;

}


int main(){
    std::string line = "42,finish_job,100";
    std::tuple<int,std::string, int> result = parser(line);
    std::cout << std::get<0>(result) << std::endl;
    std::cout << std::get<1>(result) << std::endl;
    std::cout << std::get<2>(result) << std::endl;
    return 0;

}