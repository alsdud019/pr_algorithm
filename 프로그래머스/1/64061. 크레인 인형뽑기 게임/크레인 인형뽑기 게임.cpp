#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n=board.size();
    
    vector<int> vec={-1};
    
    for (int move: moves){
        // int cnt=0;
        for (int i=0; i<n; i++){
            int new_toy=board[i][move-1];
            
            // if (cnt==1) break;
            
            if (new_toy!=0){
                //vec 추가
                if (vec.back()==new_toy){
                    answer++;
                    vec.pop_back();
                }
                else{
                    vec.push_back(new_toy);
                    
                }
                board[i][move-1]=0;
                // cnt++;
                break;
            }
            else continue;
        }
    }
    
    
    return answer*2;
}