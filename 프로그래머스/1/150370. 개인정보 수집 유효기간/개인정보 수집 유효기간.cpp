#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> term;
    
    for (string t:terms){
        stringstream ss(t);
        
        string type, month;
        ss>>type>>month;
        term[type]=stoi(month);
        cout<<type<<" "<<stoi(month)<<endl;
        // cout<<to_string(t[0])<<" "<<t[2]-'0'<<endl;;
    }
    
    int today_total=stoi(string(today,0,4))*12*28+stoi(string(today,5,2))*28+stoi(string(today,8,2));
    
    cout<<today_total<<endl;
    int i=1;
    for(string privacy:privacies){
        int year=stoi(string(privacy,0,4));
        int month=stoi(string(privacy,5,2));
        int day=stoi(string(privacy,8,2));
        
        string type=string(privacy,11,1);
        
        int total=year*12*28+month*28+day-1;
        total+=(term[type]*28);
        cout<<term[type]<<" ";
        
        cout<<"total: "<<total<<endl;
        if (total<today_total) answer.push_back(i);
        i++;
        
        
    }
    return answer;
}