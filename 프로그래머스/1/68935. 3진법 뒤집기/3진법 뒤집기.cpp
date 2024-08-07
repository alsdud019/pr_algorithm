#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int mok=0;
    vector<int> arr;
    
    while (n>=1){
        int remain=n%3;
        arr.push_back(remain);
        n=n/3;
    }
    for (int i=arr.size(); i>=0; i-- ){
        answer+=pow(3,arr.size()-i)*arr[i-1];
        
    }
    return answer;
}