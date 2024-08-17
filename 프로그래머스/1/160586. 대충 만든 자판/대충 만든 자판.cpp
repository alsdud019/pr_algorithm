#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    int arr[27]={0,};
    
    fill(arr, arr+27, 200);
    
    for (int i=0; i<keymap.size(); i++){
        for (int j=0; j<keymap[i].size(); j++){
            
            if (j<arr[keymap[i][j]-'A']) {
                arr[keymap[i][j]-'A']=j;
            }
            cout<<arr[keymap[i][j]-'A']<<endl;
        }
    }
    
    for (int i=0; i<targets.size(); i++){
        int sum=0;
        bool check=false;
        for (int j=0; j<targets[i].size(); j++){
            if (arr[targets[i][j]-'A']==200) {
                answer.push_back(-1);
                check=true;
                break;
                
            }
            else sum+=(arr[targets[i][j]-'A']+1);
        }
        if (!check) answer.push_back(sum);
    }
    
    
    return answer;
}