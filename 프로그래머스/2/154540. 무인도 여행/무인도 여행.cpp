#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

int N,M;
vector<string> MAP;

int bfs(int stY, int stX){
    queue<pair<int, int>> q;
    q.push({stY, stX});
    
    int sum=MAP[stY][stX]-'0';
    MAP[stY][stX]='X';    
    
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        
        for (int i=0; i<4; i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            
            if (ny<0 || nx <0|| ny>N-1 || nx>M-1) continue;
            if(MAP[ny][nx]=='X') continue;

            q.push({ny, nx});
            sum+=MAP[ny][nx]-'0';
            MAP[ny][nx]='X';
    
        }
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    N=maps.size();
    M=maps[0].size();
    MAP=maps;
    
    for (int  i=0; i<MAP.size(); i++){
        for (int j=0; j<MAP[0].size(); j++){
            if (MAP[i][j]!='X'){
                int re=bfs(i, j);
                answer.push_back(re);
            }
        }
    }
    sort(answer.begin(), answer.end());
    if (answer.empty()) answer.push_back(-1);
    return answer;
}