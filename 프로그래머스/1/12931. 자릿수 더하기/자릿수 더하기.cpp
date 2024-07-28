#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    
    while (n>0){
        int remain=n%10;
        answer+=remain;
        n/=10;
    }


    return answer;
}