#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> m;
    
    for (int i=0; i<players.size(); i++){
        m[players[i]]=i;

    }
    
    for (int i=0; i<callings.size(); i++){
        int now_rank=m[callings[i]];
        int before_rank=now_rank-1;
        
        m[callings[i]]--; m[players[before_rank]]++;
        
        string tmp="";
        tmp=players[now_rank];
        players[now_rank]=players[before_rank];
        players[before_rank]=tmp;
        
        
    }
    for (auto member:players){
        // cout<<member.first<<" "<<member.second<<endl;
        // answer.push_back(member.second);
        // cout<<member<<endl;
        answer.push_back(member);
    }
    
    return answer;
}