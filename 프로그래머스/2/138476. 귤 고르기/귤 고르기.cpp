#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int, int> &a,pair<int, int> &b ){
    if (a.second > b.second) return true;
    else if (a.second == b.second) return a.first < b.first;  
    else return false;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;
    
    
    for (long tanger:tangerine){
        m[tanger]++;
    }
    
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(),v.end(),cmp);
    
   // map<int, int> ::iterator it;
    for (int i=0; i<v.size(); i++){
        k-=v[i].second;
        // cout<<v[i].second<<endl;
        if (k<=0) return i+1;
    }
    
    
    return answer;
}