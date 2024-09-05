#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    map<string, int> m2;
    
    int want_s=want.size();
    int discount_s=discount.size();
    for (int i=0; i<want.size(); i++){
        m[want[i]]=number[i];
    }
    
    for (int i=0; i<=discount_s-10; i++){
        vector<string> ten_day(discount.begin()+i,discount.begin()+i+10);
        bool flag=true;
        map<string, int> m2;
        
        for (int j=0; j<10; j++){
            m2[ten_day[j]]++;
        }
        for (auto it=m.begin(); it!=m.end(); it++){
            // cout<<it->first<<" "<<m[it->first]<<" "<<m2[it->first]<<endl;
            if (m[it->first]!=m2[it->first]) { flag=false; break;}
        }
        if(flag) answer++;
        
        
    }
    return answer;
}