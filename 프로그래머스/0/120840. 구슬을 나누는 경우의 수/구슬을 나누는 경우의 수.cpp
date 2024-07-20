#include <string>
#include <vector>

using namespace std;

int factorial(int num){
    int gop=1;
    for (int i=num; i>0; i--){
        gop*=i; 
    }
    return gop;
}

long solution(int balls, int share) {
    long answer = 1;
    long all=1;
    long mok=1;
    
    if (balls==share) return 1;
    
    int small=(balls-share<share)? balls-share:share;
    
    for (int i=0; i<small; i++){
        answer*=(balls-i);
        answer/=(i+1);
    }
    
    return answer;
    
    
}