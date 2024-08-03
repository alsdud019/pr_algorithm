#include <string>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int DAT[27];
    memset(DAT, -1, sizeof(int)*27);
    
    for (int i=0; i<s.size(); i++){
        // cout<<DAT[s[i]-'a']<<" ";
        if (DAT[s[i]-'a']==-1){
            answer.push_back(-1);
        }
        else {
            answer.push_back(i-DAT[s[i]-'a']);      
        }
        
        DAT[s[i]-'a']=i;
        
    }
    return answer;
}