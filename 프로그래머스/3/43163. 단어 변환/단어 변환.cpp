#include <string>
#include <vector>
#include <iostream>

using namespace std;

int DAT[51];

int minimum=100;

int diff_one(string now, string comp){
    int cnt=0;
    for (int i=0; i<now.size(); i++){
        if (now[i]!=comp[i]) cnt++;
    }
    
    if (cnt==1) return 1;
    else return 0;
    
}

void dfs(string now, string target, int step, vector<string> words){
         
    if (now==target){
        
        if (minimum<step) return;
        
        minimum=step;
        return;
    }
       
    for (int i=0; i<words.size(); i++){
        if (diff_one(now, words[i])==1&&DAT[i]==0){
            DAT[i]=1;
                        
            dfs(words[i],target,step+1,words);
            
            DAT[i]=0;
            
        }
        
    }
        
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    dfs(begin,target,0,words);
    //cout<<diff_one("hit","hot")<<endl;
    
    //cout<<minimun<<endl;
    
    if (minimum==100) answer=0;
    else answer=minimum;
    
    return answer;
}