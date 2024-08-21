#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    string min="";
    string max="";
    sort(X.rbegin(), X.rend());
    sort(Y.rbegin(), Y.rend());
    
    if (X.size()<=Y.size()){
        min=X;
        max=Y;
    }
    else{
        max=X;
        min=Y;
    }
    
    int l_idx=0;
    int r_idx=0;
    
    while (l_idx<min.size()){
        if (min[l_idx]>max[r_idx]){
            l_idx++;
            
        }
        else if (min[l_idx]<max[r_idx]){
            r_idx++;
        }
        else{
            answer+=min[l_idx];
            l_idx++;
            r_idx++;
        }
    }
    if (answer=="") return "-1";
    if (answer[0]=='0') return "0";
    
    return answer;
}