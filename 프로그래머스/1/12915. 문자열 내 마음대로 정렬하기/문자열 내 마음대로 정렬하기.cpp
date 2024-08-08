#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool cmp(const pair<string, int> a, const pair<string, int> b ){
    if (a.second<b.second) return true;
    else if (a.second==b.second) return a.first<b.first;
    return false;
}


vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    vector<pair<string, int>> arr;
    
    for (int i=0; i<strings.size(); i++){
        arr.push_back(make_pair(strings[i],strings[i][n]));
    }
    
    sort(arr.begin(), arr.end(),cmp);
    
    for (int i=0; i<arr.size(); i++){
        answer.push_back(arr[i].first);
    }
    
    
    return answer;
}