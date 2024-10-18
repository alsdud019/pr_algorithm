#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> m;
    vector<pair<int,string>> seq;
    
    for (int i=0; i<record.size(); i++){
        stringstream ss(record[i]);
        string s1;
        ss>>s1;
        if (s1=="Enter"){
            string uid, nickname;
            ss>>uid>>nickname;
            m[uid]=nickname;
            seq.push_back(make_pair(1,uid));
            
        }
        else if (s1=="Leave"){
            string uid;
            ss>>uid;
            seq.push_back(make_pair(2,uid));
            
        }
        else if (s1=="Change"){
            string uid, nickname;
            ss>>uid>>nickname;
            m[uid]=nickname;
        }
        // cout<<s1<<endl;
    }
    for(int i=0; i<seq.size(); i++){
        int num=seq[i].first;
        string id=seq[i].second;
        string nick=m[id];
        if (num==1){
            answer.push_back(nick+"님이 들어왔습니다.");
        }
        else if (num==2){
            answer.push_back(nick+"님이 나갔습니다.");
        }
    }
    
    return answer;
}