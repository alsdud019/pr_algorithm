#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(std::vector<int> a) {
    
    
    vector<int> count(a.size());
    
    for (int i=0; i<a.size(); i++){
        count[a[i]]++;
    }
    
    if (a.size()<=1) return 0;
    
    int answer = 0;
    for (int idx=0; idx<count.size(); idx++){
        
        if (answer>=count[idx]) continue;
        
        int result=0;
        
        for (int i=0; i<a.size()-1; i++){
            if (idx!=a[i] && idx!=a[i+1]) continue;
            if (a[i]==a[i+1]) continue;
            result++;
            i++;
        }
        
        answer=max(result, answer);
        
       
    }
    
    return answer*2;
}