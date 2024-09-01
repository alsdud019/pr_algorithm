#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = -1;
    
    vector <int> pair_remove;
    
    for (int i=0; i<s.size(); i++){
        if (i==0 ||s[i]!= pair_remove.back()){
            pair_remove.push_back(s[i]);
        }
        else {
            pair_remove.pop_back();
        }
    }
    
    if (pair_remove.size()==0) answer=1;
    else answer=0;

    return answer;
}