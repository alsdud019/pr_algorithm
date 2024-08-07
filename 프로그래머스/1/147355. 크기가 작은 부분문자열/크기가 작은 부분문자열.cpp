#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    using ULL =unsigned long long;
    
    int size_p=p.size();
    ULL num_p=stoull(p);
    
    
    for (int i=0; i<=(t.size()-size_p); i++){
        string who="";
        for (int j=0; j<size_p; j++){
            who+=t[i+j];
        }
        ULL who_num=stoull(who);
        cout<<who_num<<" ";
        if (who_num<=num_p) answer+=1;
    }
    
    
    return answer;
}