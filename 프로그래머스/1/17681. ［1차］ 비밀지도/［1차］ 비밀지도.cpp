#include <string>
#include <vector>
#include <iostream>

using namespace std;

string convert(int x , int n){
    string ans="";
    for (int i=0; i<n; i++){
        int remain=x%2;
        ans=to_string(remain)+ans;
        x/=2;
    }
    return ans;
    
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i=0; i<n; i++){
        string str="";
        string arr1_str=convert(arr1[i],n);
        string arr2_str=convert(arr2[i],n);
        for (int j=0; j<n; j++){
            if(arr1_str[j]=='1' || arr2_str[j]=='1'){
                str+="#";
            }
            else if (arr1_str[j]=='0' && arr2_str[j]=='0'){
                str+=" ";
            }
        }
        answer.push_back(str);
    }
    return answer;
}