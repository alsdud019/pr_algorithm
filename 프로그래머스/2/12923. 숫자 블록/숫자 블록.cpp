#include <string>
#include <vector>
#include <cmath>

using namespace std;

using ll = long long;

ll isPrime(ll num){
    if (num==1) return 0;
    
    ll max=0;
    for (ll i=2; i<=sqrt(num); i++){
        if (num%i==0) {
            max=i;
            if (num/i<=10000000) return num/i;
        }
        
    }
    // return 1;
    if (max!=0) return max;
    else return 1;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for (ll i=begin; i<=end; i++){
        answer.push_back(isPrime(i));
    }
    
    return answer;
}