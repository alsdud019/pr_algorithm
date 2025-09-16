#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool check(long long level, vector<int> &diffs, vector<int> &times, long long limit){
    long long sum=0;
    for (int i=0; i<diffs.size(); i++){
        if (diffs[i]<=level){
            sum+=times[i];   
        }
        else {
            if (i==0) sum+=(diffs[i]-level)*times[i]+times[i];
            else sum+=(diffs[i]-level)*(times[i]+times[i-1])+times[i];
        }
    }
    if (sum <=limit) return true;
    else return false;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    long long left=1;
    long long right=*max_element(diffs.begin(), diffs.end());
    
    while(left<right){
        long long mid=(left+right)/2;
        
        if (check(mid, diffs, times, limit)) {
            right=mid;
            answer=mid;
        }
        else {
            left=mid+1;
        }
    }
    
    return right;
}