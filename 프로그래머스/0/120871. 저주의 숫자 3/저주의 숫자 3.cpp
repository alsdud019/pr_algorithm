#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector <int> arr;
    int num=0;
    
    while(arr.size()<102){
        num++;
        if (num%3==0 || to_string(num).find("3")!=string::npos){
            continue;
        }
        arr.push_back(num);
    }
    
    
    return arr[n-1];
}