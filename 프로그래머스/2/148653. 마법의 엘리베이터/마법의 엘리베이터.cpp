#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    int i=10;
    while(storey>0){
        long long remain=storey%i;
        
        long long num=remain/(i/10);
        // cout<<num<<'\n';
        if (num<5) answer+=num;
        else if (num==5){
            int calcul=((storey+i)%(i*10) - remain)/i;
            if (calcul>5 || calcul==0) storey+=i;
            answer+=num;
            
        }
        else {
            storey+=i;
            answer+=(10-num);
        }
        
        storey-=remain;
        i*=10;
        
    }
    
    return answer;
}