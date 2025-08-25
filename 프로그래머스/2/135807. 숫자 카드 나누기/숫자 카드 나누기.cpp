#include <string>
#include <vector>

using namespace std;

int gcd(int A, int B){
    if (B==0) return A;
    return gcd(B, A%B);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    // A 최대 공배수 구하기 
    int now=arrayA[0];
    for (int i=1; i<arrayA.size(); i++){
        now=gcd(now, arrayA[i]);
    }
    
    int i;
    for (i=0; i<arrayB.size(); i++){
        if (arrayB[i]%now==0) break; 
    }
    
    if (i==arrayB.size()) answer=now;
    
    //b 최대 공배수 구하기 
    now=arrayB[0];
    for (int i=1; i<arrayB.size(); i++){
        now=gcd(now, arrayB[i]);
    }
    
    int j;
    for (j=0; j<arrayA.size(); j++){
        if (arrayA[j]%now==0) break;
    }
    if (j==arrayA.size()) answer=max(answer, now);
    
    
    
    
    return answer;
}