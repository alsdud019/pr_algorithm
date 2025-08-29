#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> MAP;

int dist[101][101]={0,};
int visited[101][101]={0,};

void init(){
    for(int i=0; i<MAP.size(); i++){
        for (int j=0; j<MAP[0].size(); j++){
            dist[i][j]=1e9;
        }
    }
}

struct Node{
    int y;
    int x;
    int cost;
};

int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
int N, M;

int bfs(int stY, int stX, int endY, int endX){
    init();
    
    queue<Node> q;
    q.push({stY, stX,0});
    dist[stY][stX]=0;
    // visited[stY][stX]=1;
    
    while(!q.empty()){
        Node now=q.front(); q.pop();
        
        int y=now.y;
        int x=now.x;
        int cnt=now.cost;
        
        for (int i=0; i<4; i++){
            
            int ny=y;
            int nx=x;
            
            while(true){
                ny+=dy[i];
                nx+=dx[i];
                if (ny<0 || nx<0|| ny>N-1 || nx>M-1 || MAP[ny][nx]=='D') {
                    ny-=dy[i];
                    nx-=dx[i];
                    break;
                }
                
            }
            if (dist[ny][nx]<=cnt+1) continue;
            q.push({ny, nx, cnt+1});
            dist[ny][nx]=cnt+1;
            
        }
    }
    return dist[endY][endX];
}

int solution(vector<string> board) {
    // int answer = 0;
    
    int stY, stX, endY, endX;
    
    MAP=board;
    N=board.size();
    M=board[0].size();
    
    for (int i=0; i<board.size(); i++){
        for (int j=0; j<board[0].size(); j++){
            if (board[i][j]=='R'){
                stY=i;
                stX=j;
            }
            if (board[i][j]=='G'){
                endY=i;
                endX=j;
            }
        }
    }
    
    int answer= bfs(stY, stX, endY, endX);
    
    if (answer==1e9) return -1;
    
    return answer;
}