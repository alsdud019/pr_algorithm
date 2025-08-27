#include <iostream>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

struct Node{
    int to;
    int cost;
};

vector<Node> vec[51];
int dist[51];

void dijkstra(int N){
    for (int i=0; i<=N; i++){
        dist[i]=1e9;
    }
    
    queue<Node> q;
    q.push({1, 0});
    dist[1]=0;
    
    while(!q.empty()){
        Node now_q=q.front(); q.pop();
        
        int now=now_q.to;
        int cost=now_q.cost;
        
        for (int i=0; i<vec[now].size(); i++){
            int next=vec[now][i].to;
            int next_cost=vec[now][i].cost;
            
            if (dist[next] <= dist[now]+next_cost) continue;
            
            dist[next]=dist[now]+next_cost;
            q.push({next, next_cost});
        }
    }
    
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for (int i=0; i<road.size(); i++){
        int a=road[i][0];
        int b=road[i][1];
        int c=road[i][2];
        vec[a].push_back({b, c});
        vec[b].push_back({a,c});
    }
    
    dijkstra(N);
    
    for (int i=1; i<=N; i++){
        if (dist[i]<=K){      
            answer++;
        }
    }



    return answer;
}