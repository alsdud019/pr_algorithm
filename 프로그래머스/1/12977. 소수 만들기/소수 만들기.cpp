#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool sosu(int num){
    for (int i=2; i<=sqrt(num); i++){
        if (num%i==0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    for (int i=0; i<nums.size()-2; i++ ){
        for (int j=i+1; j<nums.size()-1; j++){
            for (int k=j+1; k<nums.size();k++){
                bool re=sosu(nums[i]+nums[j]+nums[k]);
                if (re) answer+=1;
            }
        }
    }


    return answer;
}