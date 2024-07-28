#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p_num=0;
    int y_num=0;
    
    for(int i=0; i<s.size(); i++){
        // if ('a'<=s[i] && s[i]<='z'){
        //     s[i]-=32;
        // }
        if ('A'<=s[i] && s[i]<='Z'){
            s[i]+=32;
        }
        if (s[i]=='p') p_num+=1;
        else if (s[i]=='y') y_num+=1;
    }
    if (y_num==p_num) return true;
    else return false;



    // return answer;
}