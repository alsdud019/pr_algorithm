#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    int MAX= citations.back();
    for (int i=0; i<citations.size(); i++){
        
        int H_index=citations.size()-i;
        if (citations[i]>=H_index) return H_index;
    }
    
    return answer;

}