#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int DAT[10001];
vector<string> answer;
bool isCheck;

void dfs(string now, int level, vector<vector<string>> tickets){
    
    //cout<<now<<endl;
    answer.push_back(now);
    
    if (level>=tickets.size()) {
        isCheck=true;
    }
    
    for (int i=0; i<tickets.size(); i++){
        if (tickets[i][0]==now && DAT[i]==0){
            
            DAT[i]=1;
            dfs(tickets[i][1],level+1,tickets);
            
            if (!isCheck){
                answer.pop_back();
                DAT[i]=0;
            }
        }
    }


}

vector<string> solution(vector<vector<string>> tickets) {
    string start="ICN";
    
    sort(tickets.begin(), tickets.end());
    /*for (int i=0; i<tickets.size(); i++){
        cout<<tickets[i][0]<<" "<<tickets[i][1]<<endl;
    }*/
    
    
    dfs(start,0, tickets);
    
    
    
    
    return answer;
}