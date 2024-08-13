#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    int arr[100001]={0,};
    
    for (int i=0; i<section.size(); i++){
        arr[section[i]]=1;
    }
    
    for (int i=1; i<=n; i++){
        if (arr[i]==1){
            for (int j=0; j<m; j++){
                if (i+j>n) continue;
                arr[i+j]=0;
            }
            answer+=1;
        }
    }
    
    
    
    
    return answer;
}