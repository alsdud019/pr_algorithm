#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    int d[2001]={0,};
    
    d[1]=1;
    d[2]=2;
    for (int i=3; i<=n; i++){
        d[i]=(d[i-2]+d[i-1])%1234567;
    }
    return d[n];
    
    
    // return answer;
}