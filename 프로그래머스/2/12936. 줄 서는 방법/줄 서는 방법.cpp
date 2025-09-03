#include <string>
#include <vector>

using namespace std;

vector<int> vec;
vector<int> answer;

long long factory(long long num){
    if (num==0) return 1;
    
    return num*factory(num-1);
}

void recur(long long k){
    
    if (vec.size()==1){
        answer.push_back(vec.back());
        return ;
    }
    
    long long fact=factory(vec.size()-1);
    
    for (int idx=0; idx<vec.size(); idx++){
        
        if ((idx+1) * fact>= k){
            answer.push_back(vec[idx]);
            vec.erase(vec.begin()+idx);
            k=k-((idx)*fact);
            
            recur(k);
        }
    }
}


vector<int> solution(int n, long long k) {
    
    
    for (int i=1; i<=n; i++){
        vec.push_back(i);
    }
    
    recur(k);
    
    return answer;
}