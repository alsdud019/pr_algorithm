#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> map;
    
    long long now=0;
    
    now=stoi(today.substr(0,4))*28*12+stoi(today.substr(5,2))*28+stoi(today.substr(8,2));
    
    for (int i=0; i<terms.size(); i++){
        
        stringstream ss(terms[i]);
        string type,m;
        ss>>type>>m;
        
        int month=stoi(m);
        map.insert({type, month});
    }
    
    for (int i=0; i<privacies.size(); i++){
        int year=stoi(privacies[i].substr(0,4));
        int month=stoi(privacies[i].substr(5,2));
        int day=stoi(privacies[i].substr(8,2));
        
        //개인정보 등록기간
        int privacy=year*28*12+month*28+day;
        
        //개인정보 유효기간
        string t=privacies[i].substr(11,1);
        int term=map[t];
        
        //유효기간 합한 만료날짜
        privacy+=(term*28-1);
        
        if (privacy<now){
            answer.push_back(i+1);
        }
        
        
        
        
        
    }
    
    
    
    return answer;
}