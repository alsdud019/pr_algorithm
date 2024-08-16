#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int idx=0;
    int idx_cnt=0;
    int diff_cnt=0;
    
    for (int i=0; i<s.size(); i++){
        
        if (s[i]==s[idx]) idx_cnt++;
        else if (s[i]!=s[idx]) diff_cnt++;
        
        if (idx_cnt==diff_cnt||(idx_cnt!=diff_cnt && i==s.size()-1) ) {
            answer++;
            idx=i+1;
            idx_cnt=0;
            diff_cnt=0;
        }
    }
    return answer;
}