#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int isover(vector<int> arr, int num ){
    int ans=0;
    for (int i=0; i<arr.size(); i++){
        if (arr[i]>=num) ans++;
    }
    return ans;
}

bool cmp(const pair<double, int> a, const pair<double, int> b){
    if (a.first>b.first) return true;
    else if (a.first==b.first) return a.second<b.second;
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> arr;
   
    
    
    for (int idx=1; idx<=N; idx++){
        double idx_num=count(stages.begin(), stages.end(), idx);
        double entry_num=isover(stages, idx);
        
        if (entry_num==0) arr.push_back(make_pair(0,idx));
        else arr.push_back(make_pair(idx_num/entry_num,idx));
        
        
        
    }
    sort(arr.begin(),arr.end(),cmp);
    for (int i=0; i<arr.size(); i++){
        answer.push_back(arr[i].second);
    }
 
    return answer;
}