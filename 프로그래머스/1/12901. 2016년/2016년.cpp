#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int month[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    string week[7]={"THU","FRI","SAT","SUN","MON","TUE","WED"};
    
    int month_sum=0; 
    for (int i=0; i<a-1; i++){
        month_sum+=month[i]; 
    }
    
    int day=month_sum+b;
    // cout<<day<<endl;
    answer=week[day%7];
    
    return answer;
}