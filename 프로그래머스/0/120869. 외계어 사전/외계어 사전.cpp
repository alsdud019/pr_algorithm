#include <string>
#include <vector>
#include <iostream>

using namespace std;

int compare(vector<string> spell, string str){
    int flag=0; 
    for(int i=0; i<spell.size(); i++){
        if (str.find(spell[i])!=string::npos) {flag=1;}
        else {flag=0; break;}
    }
    if (flag) return 1;
    else return 0;
}


int solution(vector<string> spell, vector<string> dic) {
    int answer = 0;
    for (int i=0; i<dic.size(); i++){
        if (compare(spell,dic[i])) {return 1; break;}
        else answer=2;
    }
    return answer;
}