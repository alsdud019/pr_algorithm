#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sum=brown+yellow;
    
    for (int i=3; i<=sum/2; i++){
        if (sum%i==0){
            int y=i;
            int x=sum/i;
            
            long long gop=(y-2)*(x-2);
            if (gop==yellow){
                answer.push_back(y);
                answer.push_back(x);
                break;
            }
        }
    }
    
    sort(answer.rbegin(), answer.rend());
    
    return answer;
}