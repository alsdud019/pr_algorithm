#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node{
    int primary_key;
    int col; 
    vector<int> vec;
    
};

bool cmp (Node left, Node right){
        
    //col이 작은 수가 우선
    if (left.col < right.col) return true;
    if (left.col > right.col) return false;
        
    //primary_key 큰게 우선 
    if (left.primary_key > right.primary_key) return true;
    if (left.primary_key < right.primary_key) return false;
        
    return false;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    // int answer = 0;
    
    vector<Node> datas;
    
    for (int i=0; i<data.size(); i++){
        int first=data[i][0];
        int col_num=data[i][col-1];
        datas.push_back({first, col_num, data[i]});
    }
    
    sort(datas.begin(), datas.end(), cmp);
    
    int answer=0;
    for (int i=row_begin-1; i<=row_end-1; i++){
        
        int sum=0;
        for (int j=0; j<datas[i].vec.size(); j++){
            // cout<<datas[i].vec[j]<<" ";
            sum+=(datas[i].vec[j]%(i+1));
        }
        // cout<<sum<<'\n';
        if (i==row_begin-1) answer=sum;
        else {
            answer=answer^sum;
        }
        
    }
    
    
    return answer;
}