#include <string>
#include <vector>
#include <iostream>

using namespace std;

int convert(int num){
    int count=0;
    while (num>0){
        int remain=num%2;
        if (remain==1) count++;
        num/=2;
    }
    // cout<<count<<endl;
    return count;
    
}


int solution(int n) {
    int answer = 0;
    
    // convert(n);
    int i=1;
    int now=n;
    while (1){
        now+=i;
        if (convert(now)==convert(n)) return now;
    }    
    
    return answer;
}