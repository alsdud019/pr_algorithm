#include <string>
#include <vector>

using namespace std;

long long cnt[1001]={0,};

long long solution(vector<int> weights) {
    long long answer = 0;      
    
    for (int i=0; i<weights.size(); i++){
        cnt[weights[i]]++;
    }
    
    for (int i=0; i<weights.size(); i++){
        int now=weights[i];
        
        
        //2:3
        if (now%2==0 && ((now/2)*3<=1000)) answer+=cnt[(now/2)*3];
        
        //3:4
        if (now%3==0 && ((now/3)*4<=1000)) answer+=cnt[(now/3)*4];
        
        //1:2
        if (now*2<=1000) answer+=cnt[now*2];
        
    }
    
    for (int i=100; i<1001; i++){
        long long n=cnt[i];
        if (n>1){
            answer+=(long long)(n*(n-1)/2);
        }    
    
    }
    
    
    
    return answer;
}