#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> done_day;
    
    for (int i=0; i<progresses.size(); i++){
        int will=100-progresses[i];
        int remain=(will%speeds[i]!=0)? 1: 0;
        // cout<<remain<<" ";
        int day=will/speeds[i]+remain;
        // cout<<day<<endl;
        done_day.push(day);
    }
    
    
    
    int max= done_day.front(); done_day.pop();
    int count=1;
    while(!done_day.empty()){
        
        int next=done_day.front(); done_day.pop();
        
        if (max<next) {answer.push_back(count); count=1;}
        else {
            count++;
        }
        if (max<next) max=next;
        if (done_day.empty()) {answer.push_back(count);}
    }
    // answer.push_back(count);
    
    return answer;
}