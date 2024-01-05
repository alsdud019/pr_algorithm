#include<vector>
#include<queue>
#include <iostream>
using namespace std;

vector<vector<int>> arr; 

int dr[]={0,0,-1,1};
int dc[]={1,-1,0,0};

int C,R;
struct Node{
    int row;
    int col;
};

int DAT[101][101];

int bfs(int stRow, int stCol, int endRow, int endCol){
    
    queue<Node> q;
    q.push({stRow, stCol});
    

    while(!q.empty()){
        Node nowNode=q.front(); q.pop();
        //cout<<nowNode.row<<" "<<nowNode.col<<endl;
        int nowRow=nowNode.row;
        int nowCol=nowNode.col;
        
        for (int i=0; i<4; i++){
            int newRow=nowRow+dr[i];
            int newCol=nowCol+dc[i];
            if (newRow<0||newCol<0||newRow>R-1||newCol>C-1)continue;
            if (arr[newCol][newRow]!=1)continue;
                 
            
            if(DAT[nowCol][nowRow]+1<DAT[newCol][newRow]||DAT[newCol][newRow]!=0) continue;
            DAT[newCol][newRow]=DAT[nowCol][nowRow]+1;
            
            if(newRow==endRow&& endCol==newCol)
                return DAT[newCol][newRow];
            q.push({newRow, newCol});
                       
        }
        
    }
    return -1;
        
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    arr=maps;
    C=maps.size(); //행
    
    R=maps[0].size(); //열
    DAT[0][0]=1;
    
    answer=bfs(0,0,R-1,C-1);
    //answer=arr[C-1][R-1];
    
    return answer;
}