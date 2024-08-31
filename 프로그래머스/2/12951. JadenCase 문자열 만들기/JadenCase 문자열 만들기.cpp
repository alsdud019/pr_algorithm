#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    // stringstream ss(s);
    
    for (int i=0; i<s.size(); i++){
        if (i==0 || (s[i-1]==' ' && s[i]!=' ')) {
            
            if ('0'<=s[i] && s[i]<='9') continue;
            else if('A'<=s[i] && s[i]<='Z') continue; 
            else s[i]-=32;
            cout<<s[i]<<" ";
        }
        else if ('A'<=s[i] && s[i]<='Z') s[i]+=32;
    }
    
    
    return s;
}