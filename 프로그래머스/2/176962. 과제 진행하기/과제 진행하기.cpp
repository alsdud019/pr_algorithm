#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<string> left, vector<string> right){
    return left[1] <right[1];
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    int now=0;
    sort(plans.begin(), plans.end(),cmp);
    
    vector<pair<string, int>> wait_vec;
    
    for (int i=0; i<plans.size(); i++){
        int new_time=stoi(plans[i][1].substr(0,2))*60+stoi(plans[i][1].substr(3,2));
        
        while(now<new_time){
            if (wait_vec.size()>0){
                wait_vec.back().second--;
                if (wait_vec.back().second==0){
                    answer.push_back(wait_vec.back().first);
                    wait_vec.pop_back();
                }
            }
            now++;
        }
        
        wait_vec.push_back({plans[i][0], stoi(plans[i][2])});
        
    }
    
    while(!wait_vec.empty()){
        answer.push_back(wait_vec.back().first);
        wait_vec.pop_back();
    }
                           
                          
    
    
    return answer;
}