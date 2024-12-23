#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    sort(wallet.begin(), wallet.end());
    sort(bill.begin(), bill.end());
    
    while(wallet[0]<bill[0] || wallet[1]<bill[1]){
        bill[1]/=2;
        sort(bill.begin(), bill.end());
        answer++;
    }
    
    
    return answer;
}