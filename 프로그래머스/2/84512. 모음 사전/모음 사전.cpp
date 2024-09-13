#include <string>
#include <vector>
#include <iostream>

using namespace std;
string gather="AEIOU";
int answer = 0;
int cnt=0;

void dfs(string target,string now){
    if (now.size()>gather.size()){
        return ;
    }
    
    if (target==now) {
        answer=cnt;
        return ;}
    cnt++;
    
    

    for (int i=0; i<gather.size(); i++){
        
        dfs(target,now+gather[i]);
        
    }
}


int solution(string word) {
    
    dfs(word,"");
    return answer;
}