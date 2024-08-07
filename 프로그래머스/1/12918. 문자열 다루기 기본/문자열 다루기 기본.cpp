#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = false;
    if (s.size()==4 || s.size()==6){
        for (int i=0; i<s.size(); i++){
            if ('0'<=s[i] && s[i]<='9') {
                answer=true;
            }
            else {
                answer=false;
                break;
            }   
        }

    }
    
    return answer;
}