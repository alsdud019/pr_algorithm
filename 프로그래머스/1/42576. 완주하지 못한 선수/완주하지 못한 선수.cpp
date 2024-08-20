#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> arr;
    
    for (int i=0; i<participant.size(); i++){
        if (arr.find(participant[i])!=arr.end()){
            arr[participant[i]]++;
        }
        else {
            arr[participant[i]]= 1;
        }
    }
    
    
    for (int i=0; i<completion.size(); i++){
        if (arr.find(completion[i])!=arr.end()){
            arr[completion[i]]--;
        }
    }
    
    for (auto it=arr.begin(); it!=arr.end(); it++){
        if (it->second==1) return it->first; 
    }
    
    // cout<<arr.begin()->first<<endl;
    
    
    return answer;
}