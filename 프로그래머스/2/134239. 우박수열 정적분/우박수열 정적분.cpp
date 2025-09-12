#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> vec;

void snow_sequence(int k){
    
    vec.push_back(k);
    while(k>1){
        if (k%2==0){
            k/=2;
        }
        else {
            k*=3;
            k+=1;
        }
        vec.push_back(k);
    }
    
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    snow_sequence(k);
    
    for (int i=0; i<ranges.size(); i++){
        int start=ranges[i][0];
        int end=(vec.size()-1)+ranges[i][1];
        
        if (start==end){
            answer.push_back(0);
            continue;
        }
        if (start>end){
            answer.push_back(-1);
            continue;
        }
        
        double sum=vec[start]+vec[end];
        for (int j=start+1; j<end; j++){
            sum+=(vec[j]*2);
        }
        answer.push_back(sum/2);
        
    }
   
    
    
    return answer;
}