#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> answer;
    vector<int> ans;
    for (int i=0; i<numbers.size()-1; i++){
        for (int j=i+1; j<numbers.size(); j++){
            int sum=numbers[i]+numbers[j];
            answer.insert(sum);
        }
    }
    set<int> :: iterator it;
    for (it=answer.begin(); it!=answer.end(); it++){
        ans.push_back(*it);
    }
    return ans;
}