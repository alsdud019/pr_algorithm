#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<int, string> m1;
    map<string, int> m2;
    
    for (int i=0; i<players.size(); i++){
        m1[i]=players[i];
        m2[players[i]]=i;
    }
    
    for (auto who:callings){

        int now_rank=m2[who];
        // cout<<now_rank<<endl;
        string before_name=m1[now_rank-1];
        
        m1[now_rank-1]=who;
        m1[now_rank]=before_name;
        
        m2[who]=now_rank-1;
        m2[before_name]=now_rank;
    }
    for (auto member:m1){
        // cout<<member.first<<" "<<member.second<<endl;
        answer.push_back(member.second);
    }
    
    return answer;
}