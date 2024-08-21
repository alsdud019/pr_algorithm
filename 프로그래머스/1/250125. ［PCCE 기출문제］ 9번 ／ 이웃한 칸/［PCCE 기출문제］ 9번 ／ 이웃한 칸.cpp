#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int dr[]={0,0,-1,1};
    int dc[]={1,-1,0,0};
    
    int length=board.size();
    // cout<<n<<endl;
    
    string now=board[h][w];
    
    for (int i=0; i<4; i++){
        int nh=dc[i]+h;
        int nw=dr[i]+w;
        
        if (nh<0 || nw<0 || nh>=length || nw>=length) continue;
        
        if (board[nh][nw]==now) answer++;
    }
    
    
    return answer;
}