#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    int jump=0;
    while (n>0){
        //홀수일때 
        if (n%2!=0){
            n-=1;
            jump++;
            n/=2;
        }
        else if (n%2==0){
            n/=2;
        }
    }
    
    // cout<<jump<<endl;
    


    return jump;
}