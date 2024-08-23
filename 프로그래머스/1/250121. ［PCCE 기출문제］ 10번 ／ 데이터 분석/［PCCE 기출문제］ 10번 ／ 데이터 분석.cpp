#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int num=-1;

bool cmp(const vector<int>a,const vector<int>b){
    if (a[num]<b[num]) return true;
    else return false;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<string, int> m;
    m["code"]=0;
    m["date"]=1;
    m["maximum"]=2;
    m["remain"]=3;
    
    num=m[sort_by];
    
    for (int i=0; i<data.size(); i++){
        int ext_idx=m[ext];
        if(data[i][ext_idx] < val_ext){
            answer.push_back(data[i]);
        }
    }
    sort(answer.begin(), answer.end(), cmp);
    
    return answer;
}