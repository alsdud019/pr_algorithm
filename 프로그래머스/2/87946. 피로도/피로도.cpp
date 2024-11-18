#include <string>
#include <vector>

using namespace std;

int answer = -1;
int DAT[9]={0,};

void backtracking(int level, int k, vector<vector<int>> dungeons){
    
    if (k<=0){
        return ;
    }
    
    if (answer<level){
        answer=level;
    }
    
    for (int i=0; i<dungeons.size(); i++){
        int comein=dungeons[i][0];
        int use=dungeons[i][1];
        
        
        if (DAT[i]==1) continue;
        if (comein>k) continue;
        DAT[i]=1;
        backtracking(level+1, k-use, dungeons);
        DAT[i]=0;
    }
    
    
    
}

int solution(int k, vector<vector<int>> dungeons) {

    backtracking(0, k, dungeons);
    
    
    return answer;
}