#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<string, string>> seperate(string p){
    vector<pair<string, string>> vec;
    
    string u="";
    string v="";
    
    int left_cnt=0;
    int right_cnt=0;
    for (int i=0; i<p.size(); i++){
        
        if (p[i]=='(') left_cnt++;
        else if (p[i]==')') right_cnt++;
        
        if (left_cnt!=0 && (left_cnt==right_cnt)){
            u=string(p.begin(), p.begin()+i+1);
            v=string(p.begin()+i+1, p.end());
            break;
        }
    }
    // cout<<v<<'\n';
    vec.push_back({u,v});
        
    return vec;
}
bool isRight(string u){
    
    if (u=="") return true;
    
    vector<char> stack;
    for (int i=0; i<u.size(); i++){
        if (i==0 && (u[i]==')')) return false;
        else{
            if (!stack.empty() && (stack.back()=='(' && u[i]==')')){
                stack.pop_back();
                continue;
            }
            stack.push_back(u[i]);
        }
    }
    if (stack.empty()) return true;
    else return false;
}

string reverse(string u){
    string result="";
    for (int i=0; i<u.size(); i++){
        if (i==0 || i==u.size()-1) continue;
        if (u[i]=='(') result+=')';
        else if (u[i]==')') result+='(';
        
    }
    return result;
}

string recur(string p){
    
    string result = "";
    
    vector<pair<string, string>>vec =seperate(p);
    
    string u=vec[0].first;
    string v=vec[0].second;
    
    //올바른 문장이라면
    if (isRight(u)){
        if (u!="") result+=u;
        if (v!="") result+=recur(v);
    }
    
    //올바른 문장이 아니라면
    else{
        result+="(";
        if (v!="") result+=recur(v);
        result+=")";
        if (reverse(u)!="") result+=reverse(u);
    }
    
    return result;
}

string solution(string p) {
    
    string answer="";
    
    answer=recur(p);
    
    return answer;
}