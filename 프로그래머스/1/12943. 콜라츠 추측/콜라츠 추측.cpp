#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    // int answer = 0;
    int cnt=0;
    long long num_=num;
    if (num_==1) return 0;
    while (1){

        if (num_%2==0){
            num_/=2;
            cnt+=1;
        }
        else{
            num_=num_*3+1;
            cnt+=1;
        }
        if (num_==1){
            return cnt;
        }
        if (cnt>=500) return -1;
    }
    // return answer;
}