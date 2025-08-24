#include <string>
#include <vector>
#include <iostream>

using namespace std;

int now_server[25]={0,};

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    for (int i=0; i<players.size(); i++){
        int man=players[i];
        int need=man/m;
        
        int now_server_cnt=now_server[i];
        //서버 증설이 필요하다면
        if (now_server_cnt<need){
            int diff=need-now_server_cnt;
            
            for (int j=0; j<k; j++){
                if (i+j>25) continue;
                now_server[i+j]+=diff;
            }
            answer+=diff;
        }
        // cout<<now_server[i]<<" ";
    }
    
    
    return answer;
}