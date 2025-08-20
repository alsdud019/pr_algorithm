#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (auto num: numbers){
        long long now=num;
        
        if (now%2==0) answer.push_back(num+1);
        
        else{
            long long bit=1;
            while(1){
                if ((now&bit)==0) break;
                bit*=2;
            }
            bit/=2;
            
            answer.push_back(now+bit);
        }
    }
    

    
    return answer;
}