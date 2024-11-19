#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int visited[9]={0,};
set<int> s;

bool check(int num){
    for (int i=2; i<=sqrt(num); i++){
        if (num%i==0){
            return false;
        }
    }
    return true;
}

void dfs(string now, string numbers){
    // cout<<now<<endl;
    
    if (now!="" && stoi(now)>1){
        if (check(stoi(now))){
        s.insert(stoi(now));
        // cout<<now<<endl;
    }
    }

    
    
    for (int i=0; i<numbers.size(); i++){
        
        if (visited[i]==1) continue;
        char next=numbers[i];
        visited[i]=1;
        dfs(now+next, numbers);
        visited[i]=0;
        
    }
}

int solution(string numbers) {
    int answer = 0;
    
    dfs("",numbers);
    // cout<<check(stoi("110"))<<endl;
    
    cout<<s.size()<<endl;
    
    return s.size();
}