#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i=0; i<commands.size(); i++){
        int start=commands[i][0]-1;
        int end=commands[i][1]-1;
        int cnt=commands[i][2]-1;
        vector<int> slice;
        
        for (int j=start; j<=end;j++){
            slice.push_back(array[j]);
        }
        sort(slice.begin(),slice.end());
        
        answer.push_back(slice[cnt]);
    }

    return answer;
}