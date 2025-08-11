#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[1000001]={0,};
int answer=1e9;

void bfs(int st, int end, int n){
    
    queue<pair<int,int>> q;
    
    q.push({st, 0});
    visited[st]=1;
    
    while(!q.empty()){
        pair<int, int> now=q.front();
        q.pop();
        
        if (now.first==end){
            answer=min(answer,now.second);
        }
        
        for (int i=0; i<3; i++){
            
            int next;
            if (i==0){
                next=now.first*3;
            }
            else if (i==1){
                next=now.first*2;
            }
            else {
                next=now.first+n;
            }
            
            if (next>end || visited[next]==1)continue;
            visited[next]=1;
            q.push({next, now.second+1});
            
        }
    }
    
}

int solution(int x, int y, int n) {
    // int answer = 0;
    
    bfs(x,y,n);
    if (answer>=1e9) return -1;
    else return answer;
}