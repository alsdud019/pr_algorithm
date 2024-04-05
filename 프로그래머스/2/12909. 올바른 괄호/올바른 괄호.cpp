#include<string>
#include <iostream>
#include <stack> 

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> gstack;
    // char open[1]='(';
    // string close=")";
        
    
    for (int i=0; i<s.size(); i++){
        if (s[i]=='('){
            gstack.push(s[i]);
        }
        else if (s[i]==')'){
            if (gstack.size()==0){
                answer=false;
                break;
            }
            gstack.pop();
        }
    }
    if (gstack.size()!=0){
        answer=false;
    }
    
    
    return answer;
}