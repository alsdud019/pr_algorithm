#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include <iostream>

using namespace std;
int visited[101]={0,};
vector<int> vec[101];

int bfs(int start, int end){
    
    queue<int> q;
    q.push(start);
    
    //두 송전탑을 끊는다. 
    visited[start]=1;
    visited[end]=1;
    
    //자기 자신을 센다. 
    int cnt=1;
    
    while(!q.empty()){
        
        int now=q.front(); q.pop();
        
        for (int i=0; i<vec[now].size(); i++){
            int next=vec[now][i];
            
            if (visited[next]==1) continue;
            visited[next]=1;
            q.push(next);
            cnt++;
            
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9;
    
    for (int i=0; i<wires.size(); i++){
               
        int start=wires[i][0];
        int end=wires[i][1];
        
        vec[start].push_back(end);
        vec[end].push_back(start);
    }
    
    //간선마다 탐색 
    for (int i=0; i<wires.size(); i++){
        memset(visited, 0, sizeof(visited));
        
        int start=wires[i][0];
        int end=wires[i][1];
        
        int left=bfs(start, end);
        int right=n-left;
        
        answer=min(answer, abs(left-right));
        
  
    }
    
    
    return answer;
}