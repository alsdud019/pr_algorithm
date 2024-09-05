#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort (people.begin(), people.end());
    
    int idx=0;
    while (people.size()>idx){
        int back=people.back();
        
        if (people[idx]+back<=limit){answer++; idx++;}
        else answer++;
        people.pop_back();
    }
    
    
    return answer;
}