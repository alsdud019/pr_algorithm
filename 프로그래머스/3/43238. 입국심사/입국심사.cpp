#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    
    long long left=1;
    long long right=n*(long long)times[times.size()-1];
    // cout<<right<<endl;
    
    while(left<=right){
        long long mid=(left+right)/2;
        long long passanger=0;
        
        for (int i=0; i<times.size(); i++){
            passanger+=(mid /(long long)times[i]);
            // cout<<mid<<" : "<<passanger<<endl;    
        }
        
        if (passanger>=n){
            answer=mid;
            right=mid-1;
        }
        else {
            left=mid+1;
        }
    }
    
    
    return answer;
}