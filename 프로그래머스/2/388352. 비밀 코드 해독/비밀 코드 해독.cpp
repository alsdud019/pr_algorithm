#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> vec;

int answer = 0;

vector<vector<int>> qes;
vector<int> a;

bool check(){
    
    for (int k=0; k<qes.size(); k++){
        int cnt=0;
        for (int i=0; i<5; i++){
            for (int j=0; j<5; j++){
                if (vec[i]==qes[k][j]){
                    cnt++;
                    break;
                }
            }
        }
        if (cnt!=a[k]) return false; 
    }
    
    return true;   
}

void recur(int level, int n, int idx){
    
    if (level==5){
        // for (auto a:vec){
        //     cout<<a<<" ";
        // }
        // cout<<'\n';
        if (check()) {
            answer++;
            // for (auto a:vec){
            //     cout<<a<<" ";
            // }
            // cout<<'\n';
        }
        return ;
    }
    
    for (int i=idx; i<=n; i++){
        
        vec.push_back(i);
        recur(level+1, n, i+1);
        vec.pop_back();
    }
    
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    
    a=ans;
    qes=q;
    
    recur(0,n,1);
    
    return answer;
}