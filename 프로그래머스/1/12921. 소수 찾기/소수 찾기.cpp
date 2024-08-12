#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int arr[1000001]={0,};
    
    for (int i=2; i<=n; i++){
        if (arr[i]==0) {
            answer+=1;
        }
        for (int j=i*2; j<=n; j+=i){
            arr[j]=1;
        }
    }
    
    

    return answer;
}