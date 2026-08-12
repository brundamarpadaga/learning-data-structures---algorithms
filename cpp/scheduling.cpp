/* You are given rows of input, each formatted as "job_id,start_time,duration". Parse all rows, then output the job IDs in order of earliest start time. If two jobs start at the same time, output the one with shorter duration first.


Input:
"3,10,5"
"1,7,3"
"2,10,2"

Output: 1 2 3 */


#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
#include<algorithm>

struct Job{
    int job_id, start_time, duration;

};

std::vector<int> scheduler( std::vector<Job> jobs){

    struct {
        bool operator()(const Job& a, const Job& b){
            if(a.start_time == b.start_time){
                if(a.duration == b.duration){
                    return a.job_id < b.job_id;
                }
                else{
                    return a.duration < b.duration;
                }
            }
            else{
                return a.start_time < b.start_time;
            }
        }
    } scheduleComp;

    std::sort(jobs.begin(),jobs.end(), scheduleComp );

    std::vector<int> result;
    for( Job job : jobs){
        result.push_back(job.job_id);
    }

    return result;
    
}

int main() {
    std::string line;
    std::vector<Job> jobs;
    std::string token;
    
    while (std::getline(std::cin, line)) {
        
        std::stringstream stream(line);
        std::vector<std::string> tokens;

        while(std::getline(stream, token,',')){
            tokens.push_back(token);
            // now tokens = {"3,10,5"}
        }

        Job job ;
        job.job_id = std::stoi(tokens[0]);
        job.start_time = std::stoi(tokens[1]);
        job.duration = std::stoi(tokens[2]);

        jobs.push_back(job);
    }

    std::vector<int> result = scheduler(jobs);

    for ( int i : result){
        std::cout << i << std::endl;
    }
    
}