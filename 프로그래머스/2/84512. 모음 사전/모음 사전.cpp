#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool flag=false;
int answer=-1;
string code="AEIOU";
int cnt=-1;

void dfs(string word, string now){
    if (flag || now.size()>5){
        return ;
    }
    
    cnt++;
    // cout<<now<<" "<<cnt<<endl;
    
    if (now==word){
        flag=true;
        answer=cnt;
        return ;
    }
    
    for (int i=0; i<code.size(); i++){
        dfs(word, now+code[i]);
    }
    
}
int solution(string word) {
    
    dfs(word,"");
    

    return answer;
}