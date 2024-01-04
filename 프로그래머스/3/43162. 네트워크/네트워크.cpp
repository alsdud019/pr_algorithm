#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> arr;
int DAT[200];

void dfs(int level){
    
    DAT[level]=1;
    
    for (int i=0; i<arr[level].size(); i++){
        if (DAT[i]==1)continue;
        if (i!=level && arr[level][i]==1){
            
            dfs(i);
        }
    }
    
    
} 

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    arr=computers;
    
    for (int i=0; i<n; i++){
        if (DAT[i]!=1){
            dfs(i);
            answer++;
        }
        
    }
    
    return answer;
}