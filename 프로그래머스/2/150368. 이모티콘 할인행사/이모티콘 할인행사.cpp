#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> vec;
// priority_queue<pair<int, int>> pq;
vector<int> answer={0,0};

void find(vector<vector<int>> users, vector<int> emoticons){
    
    int plus=0;
    int total=0;
    
    for (int i=0; i<users.size(); i++){
        int user_per=users[i][0];
        int user_money=users[i][1];
        
        int sum=0;
 
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
    
    // if (plus!=0 || total!=0) pq.push({plus, total});
    answer=max(answer, {plus, total});
}

void recur(int n, int level, vector<vector<int>> users, vector<int> emoticons){
    
    if (level==n){
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
    
    
    recur(emoticons.size(),0,users, emoticons);

    // answer.push_back(pq.top().first);
    // answer.push_back(pq.top().second);
    return answer;
}