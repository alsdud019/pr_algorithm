#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> arr;
    while (n>0){
        int remain=n%10;
        arr.push_back(remain);
        n/=10;
    }
    sort(arr.rbegin(), arr.rend());
    int ten=pow(10,arr.size()-1);

    
    for (int i=0; i<arr.size(); i++){
        answer+=arr[i]*ten;
        ten/=10;
        
    }
    
    return answer;
}