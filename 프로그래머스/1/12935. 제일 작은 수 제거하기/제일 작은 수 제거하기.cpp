#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int min=99999;
    for (int i=0; i<arr.size(); i++){
        if (arr[i]<min) {
            min=arr[i];
        }
    }
    
    for (int i=0; i<arr.size(); i++){
        if (arr[i]==min) continue;
        answer.push_back(arr[i]);
    }
    if (answer.size()<1) answer.push_back(-1);

    
    return answer;
}