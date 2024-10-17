#include <string>
#include <vector>
#include <iostream>
// #include <cstdlib>
// #include <typeinfo>
#include <set>
#include <cmath>

using namespace std;

string number;
int visited[9]={0,};
string str="";
set<long long> s;

bool check(long long num){
    if (num==0 || num==1) return false;
    for (int i=2; i<= sqrt(num); i++){
        if (num%i==0) return false;
    }
    return true;
}

void dfs(int level, string str){
    if (level<=number.size() && str!=""){
        // cout<<str<<endl;
        
        if (check(stoi(str))){
            s.insert(stoi(str));
        }
        
    }
    
    for (int i=0; i<number.size(); i++){
        if (visited[i]==1) continue;
        
        visited[i]=1;
        dfs(level+1, str+number[i]);    
        visited[i]=0;

    }
    
}

int solution(string numbers) {
    int answer = 0;
    
    number=numbers;
    
    // visited[0]=1;
    dfs(0, "");
    
    
//     for (auto it=s.begin(); it!=s.end(); it++){
//         // int num=stoi();
        
//         // if (check(*it)) {
//         //     answer++;
//         // };
//         cout<<*it<<endl;
//     }
    return s.size(); 
    
    //return answer;
}