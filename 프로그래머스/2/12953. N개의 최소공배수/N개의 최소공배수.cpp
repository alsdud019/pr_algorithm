#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int gcd(int a, int b){
    int MAX=max(a,b);
    int MIN=min(a,b);
    
    while (MAX % MIN !=0){
        int remain= MAX % MIN;
        MAX=MIN;
        MIN=remain;
    }
    return MIN;
}

int solution(vector<int> arr) {
    int answer = 0;
    
    int now=arr[0];
    for (int i=1; i<arr.size(); i++){
        now=now * arr[i] /gcd(now, arr[i]);
    }

    return now;
}