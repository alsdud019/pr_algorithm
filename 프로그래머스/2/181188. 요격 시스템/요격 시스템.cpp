#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> left, vector<int> right){
    return left[1] < right[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(),cmp);
    
    int end=targets[0][1];
    for (int i=1; i<targets.size(); i++){
        int start=targets[i][0];
        if (start<end) continue;
        else{
            end=targets[i][1];
            answer++;
        }
    }
    
    
    return answer+1;
}