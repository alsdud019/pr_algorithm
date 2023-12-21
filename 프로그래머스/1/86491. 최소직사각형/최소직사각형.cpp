#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;




int solution(vector<vector<int>> sizes) {
    int answer = 0;
    //cout<<sizes.size()<<endl;
    priority_queue <int, vector<int>, less<int>> smaller;
    priority_queue <int, vector<int>, less<int>> bigger;
    
    for (int i=0; i<sizes.size(); i++){
        if (sizes[i][0]<=sizes[i][1]){
            smaller.push({sizes[i][0]});
            bigger.push({sizes[i][1]});
        }
        else {
            smaller.push({sizes[i][1]});
            bigger.push({sizes[i][0]});
        }
    }
    
    //cout<<smaller.top()<<" "<<bigger.top()<<endl;
    answer=smaller.top()*bigger.top();
    
    return answer;
}