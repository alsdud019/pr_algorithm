#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int visited[101][101]={0,};
int MAP[101][101];
int N, M;

void init(int n, int m){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            MAP[i][j]=1e9;
        }
    }
    memset(visited, 0, sizeof(visited));
}

struct Node{
    int y;
    int x;
};

int dy[]={0,0,-1,1};
int dx[]={1,-1,0,0};

int bfs(int stY, int stX, int endY, int endX, vector<string> maps){
    init(N, M);
    
    queue<Node> q; //{y, x}
    q.push({stY, stX});
    
    visited[stY][stX]=1;
    MAP[stY][stX]=0;
    
    while(!q.empty()){
        Node now=q.front(); q.pop();
        int y= now.y;
        int x=now.x;
        
        if (y==endY && x==endX) break;
        
        for (int i=0; i<4; i++){
            int ny=dy[i]+y;
            int nx=dx[i]+x;
            
            if (ny<0 || nx<0|| ny>N-1 || nx>M-1) continue;
            if (maps[ny][nx]=='X' || visited[ny][nx]==1) continue;
            if (MAP[ny][nx] <=MAP[y][x]+1) continue;
            
            q.push({ny, nx});
            visited[ny][nx]=1;
            MAP[ny][nx]=MAP[y][x]+1;
        }
    }
    
    return MAP[endY][endX];
}


int solution(vector<string> maps) {
    int answer = 0;
    
    int stX, stY;
    int leX, leY;
    int endX, endY;
    
    //각 노드 값 저장하기 
    for (int i=0; i<maps.size(); i++){
        for (int j=0; j<maps[0].size(); j++){
            if (maps[i][j]=='S') {
                stY=i; stX=j;
            }
            else if (maps[i][j]=='L'){
                leY=i; leX=j;
            }
            else if (maps[i][j]=='E'){
                endY=i; endX=j;
            }
        }
    }
    
    N=maps.size(); M=maps[0].size();
    
    int start=bfs(stY, stX, leY, leX, maps);
    if (start==1e9) return -1;
    
    int end=bfs(leY, leX, endY, endX, maps);
    if (end==1e9) return -1;
    
    // cout<<start<<" "<<end;
    
    answer=start+end;
    
    return answer;
}