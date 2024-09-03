#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int who=-1;
    for (int i=0; i<words.size(); i++){
        
        if (i==0) continue;
        string now=words[i];
        string fore=words[i-1];
        
        if (now[0]!=fore[fore.size()-1] || now.size()==0) {
            // cout<<i+1<<" "<<now<<endl;
            who=i+1;
            break;
        }
        else if (find(words.begin(), words.begin()+(i-1), now)!=words.begin()+(i-1)){
            // cout<<i+1<<" "<<now<<endl;
            who=i+1;
            break;
        }
        
    }
    if (who==-1) return {0,0};
    else {
        int remain=who%n;
        int mok=who/n+1;
        if (remain==0){
            remain=n;
            mok-=1;
        }
        return {remain, mok};
    }

    // return answer;
}