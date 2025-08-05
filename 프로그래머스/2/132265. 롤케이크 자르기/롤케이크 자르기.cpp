#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt[2][10001];

int solution(vector<int> topping) {
    int answer = 0;
    
    int left=0;
    int right=0;
    
    //idx가 1일때 
    for (int i=0; i<topping.size(); i++){
        if (i==0){
            left++;
            cnt[0][topping[i]]++;
        }
        else{
            cnt[1][topping[i]]++;
            if (cnt[1][topping[i]]==1) right++;
        }
    }
    
    if (right>0){
        for (int idx=1; idx<topping.size()-2; idx++){
            int now=topping[idx];
            
            if (cnt[0][now]<1) left++;
            cnt[0][now]++;
            cnt[1][now]--;
            
            if (cnt[1][now]<1) right--;
            
            if (left==right) answer++;
            // cout<<left<<" "<<right<<'\n';
        }
    }
    else return answer;

    
    return answer;
}