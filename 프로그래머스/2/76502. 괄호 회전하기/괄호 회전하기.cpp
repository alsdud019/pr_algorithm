#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string plus=s+s;
    
    for (int i=0; i<s.size(); i++){
        string str=string(plus.begin()+i, plus.begin()+i+s.size());
        
        bool flag=true;
        vector<char> check;
        for (int j=0; j<str.size(); j++){
            if (str[j]=='(' || str[j]=='{'||str[j]=='['){
                check.push_back(str[j]);
            }
            
            else{
               if (check.empty()) {
                   flag=false;
                   break;
               }
                else if (
                str[j]==')' && check.back()!='('||
                str[j]==']' && check.back()!='['||
                str[j]=='}' && check.back()!='{'){
                    flag=false;
                    // cout<<check.back()<<endl;
                    break; 
                } 
                else check.pop_back();
            }
            
        }
        
        if (flag && check.empty()) answer++;
        
    }
    return answer;
}