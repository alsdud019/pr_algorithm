#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> vec;
vector<pair<int, long long>> ans={{0,0}};
priority_queue<pair<int, long long>> pq;

void find(vector<vector<int>> users, vector<int> emoticons){
    
    int plus=0;
    long long total=0;
    
    for (int i=0; i<users.size(); i++){
        int user_per=users[i][0];
        long long user_money=users[i][1];
        
        long long sum=0;
 
        for (int k=0; k<vec.size(); k++){
            if (vec[k]>=user_per){
                sum+=emoticons[k]*(100-vec[k])/100;
            }
        }
        
        if (sum>=user_money) {
            plus++;
        }
        else total+=sum;
    }
    
    if (plus!=0 || total!=0) {
        pq.push({plus, total});
        // cout<<plus<<" "<<total<<'\n';
    }
    
    
}

void recur(int n, int level, vector<vector<int>> users, vector<int> emoticons){
    
    if (level==n){
        // for (auto a:vec){
        //     cout<<a<<" ";
        // }
        // cout<<'\n';
        find(users,emoticons);
        return ;
    }
    
    for (int i=1; i<5; i++){
        vec.push_back(i*10);
        recur(n, level+1,users, emoticons);
        vec.pop_back();
    }
    
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    recur(emoticons.size(),0,users, emoticons);
    // cout<<pq.top().first<<" "<<pq.top().second;
    answer.push_back(pq.top().first);
    answer.push_back(pq.top().second);
    return answer;
}