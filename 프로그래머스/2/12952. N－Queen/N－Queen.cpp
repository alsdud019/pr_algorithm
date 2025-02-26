#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;
int visited[15];
vector<int> vec;
int answer = 0;

bool check(int now){
    bool flag=true;
    int now_level=vec.size();
    
    for (int i=0; i<vec.size(); i++){

        if (abs(now-vec[i]) == abs(i-now_level)){
            flag=false;
            break;
        }
        // if (!flag) return false;
    }
    if (flag) return true;
    else return false;
            
}

void dfs(int N, int level){
    
    if (level==N){
        // for (auto v:vec){
        //     cout<<v<<" ";
        // }
        // cout<<endl;
        answer++;
    }
    
    for (int i=0; i<N; i++){
        if (visited[i]) continue;
        
        if (check(i)){
            visited[i]=1;
            vec.push_back(i);
            dfs(N, level+1);
            visited[i]=0;
            vec.pop_back();
        } 
    } 
}

int solution(int n) {
    
    dfs(n,0);
    
    return answer;
}