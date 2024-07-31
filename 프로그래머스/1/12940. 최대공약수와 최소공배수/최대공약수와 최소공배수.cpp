#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int max=0;
    int min=0;
    for (int i=1; i<=n; i++){
        if (n%i==0 && m%i==0){
            max=i;
        }
    }
    
    int i=1;
    while (1){
        int n_=n*i;
        if (n_%m==0) {
            min=n_;
            break;}
        
        i+=1;
    }
    
    return answer={max,min};
}