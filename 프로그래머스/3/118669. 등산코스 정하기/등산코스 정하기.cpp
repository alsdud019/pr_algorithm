#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <queue>


using namespace std;

struct Node{
    int to;
    int w;
};

struct cmp{
    bool operator()(Node a, Node b){
        if (a.w < b.w) return false;
        if (a.w> b.w) return true;
        
        if (a.to < b.to) return false;
        if (a.to> b.to) return true;
        

        return false;
    }
};

vector<Node> vec[50001];
queue<Node>q;
int summit[50001];
priority_queue<Node, vector<Node>, cmp> pq;
int dist[50001];
vector<int> answer;

void bfs(){
    
    while(!q.empty()){
        Node now=q.front(); q.pop();
        int now_num=now.to;
        int now_w=now.w;
        
        if (summit[now_num]){
            pq.push({now_num, now_w});
            continue;
        }          
        
        for (int i=0; i<vec[now_num].size(); i++){
            int next=vec[now_num][i].to;
            int cost=vec[now_num][i].w;
            
            //숫자가 더 큰걸 저장해야한다. 만약 다음 숫자가 작으면 안들어감 
            if (dist[next]!=-1e9 && dist[next] <= max(cost, now_w)) continue; 
            dist[next]=max(cost, now_w);
            q.push({next, max(cost, now_w)});
        }
    }
    
    // while(!pq.empty()){
    //     Node s=pq.top();
    //     cout<<s.to<<" "<<s.w<<endl;
    //     pq.pop();
    // }
    answer.push_back(pq.top().to);
    answer.push_back(pq.top().w);
}


vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    
    
    for (int i=0; i<paths.size(); i++){
        int from=paths[i][0];
        int to=paths[i][1];
        int w=paths[i][2];
        
        //양방향
        vec[from].push_back({to, w});
        vec[to].push_back({from, w});
        
    }
    
    for (int i=1; i<=n; i++){
        dist[i]=-1e9;
    }
    
    for (int i=0; i<gates.size(); i++){
        q.push({gates[i],0});
        dist[gates[i]]=0;
    }
    
    for (int i=0; i<summits.size(); i++){
        summit[summits[i]]=1;
    }
    
    
    bfs();
    
    
    
    
    return answer;
}