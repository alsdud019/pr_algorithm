#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int remain=0;
    while (n>=a){
        if (n%a==0){
            answer+=(n/a)*b;
            n=(n/a)*b;
        }
        else {
            // remain+=n%a;
            answer+=(n/a)*b;
            n=(n/a)*b+(n%a);
        }
        
    }
        
    
    return answer;
}