#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for (int j=0; j<queries.size(); j++){
        // 크기 할당 
        vector<int> arr2=vector<int>(arr.begin()+queries[j][0],arr.begin()+queries[j][1]+1);
        sort(arr2.begin(),arr2.end());

        int flag=0;
        for (int i=0; i<arr2.size(); i++){
            if (arr2[i]>queries[j][2]) {
                flag=1; 
                answer.push_back(arr2[i]); 
                break;}
            else continue;
        }
        if (!flag) answer.push_back(-1);
        
    }

    return answer;
}