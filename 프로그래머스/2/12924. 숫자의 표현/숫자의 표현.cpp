#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i=1; i<=n; i++){
        int sum=0; 
        int idx=i;
        while (1){
            sum+=idx;
            if (sum==n) {
                answer++;
                // cout<<i<<endl;
                break;
            }
            else if (sum>n) break;
            idx++;
        }
    }
    return answer;
}