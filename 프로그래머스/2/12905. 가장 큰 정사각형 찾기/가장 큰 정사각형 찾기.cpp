#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer=board[0][0];
    
    for (int i=0; i<board.size(); i++){
        for (int j=0; j<board[0].size(); j++){
            
            if (board[i][j]==0) continue;
            
            if (i-1<0 || j-1<0) {
                answer=max(board[i][j], answer);
            }
            else{
            
                board[i][j]=min({board[i][j-1], board[i-1][j], board[i-1][j-1]})+1;
                answer=max(board[i][j],answer);
            }
        
            
        }
    }
    
    return answer*answer;
}