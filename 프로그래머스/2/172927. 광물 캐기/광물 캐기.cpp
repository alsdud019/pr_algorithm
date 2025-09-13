#include <string>
#include <vector>

using namespace std;

int stress[3][3]={{1,1,1},{5,1,1},{25,5,1}};

int answer = 1e9;

bool check(vector<int> picks){
    for (int i=0; i<picks.size(); i++){
        if (picks[i]!=0) return false;
    }
    return true;
}

int change(string str){
    if (str=="diamond") return 0;
    else if (str=="iron") return 1;
    else if (str=="stone") return 2;
}

void dfs(int now_mineral, int sum, vector<int> picks, vector<string> minerals){
    
    if (check(picks) || now_mineral>=minerals.size()){
        answer=min(answer, sum);
        return ;
    }
    
    for (int i=0; i<3; i++){
        
        if (picks[i]==0) continue;
        picks[i]--;
        
        //광물 캐기
        int tmp_mineral=now_mineral;
        int tmp_sum=sum;
        for (int k=0; k<5; k++){
            int mineral_num=change(minerals[tmp_mineral]);
            tmp_sum+=stress[i][mineral_num];
            tmp_mineral++;
            if (tmp_mineral>minerals.size()-1) break;
        }
        
        dfs(tmp_mineral, tmp_sum, picks, minerals) ;
        picks[i]++;
        
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    
    
    dfs(0, 0,picks,minerals );
    
    return answer;
}