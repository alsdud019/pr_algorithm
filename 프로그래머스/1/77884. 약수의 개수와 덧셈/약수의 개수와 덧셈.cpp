#include <string>
#include <vector>

using namespace std;

int ack_num(int num){
    int ack=0;
    for (int i=1; i<num+1; i++){
        if (num%i==0){
            ack+=1;
        }
    }
    return ack;
}

int solution(int left, int right) {
    int answer = 0;
    for (int i=left; i<right+1;i++){
        if (ack_num(i)%2==0){
            answer+=i;
        }
        else answer-=i;
    }
    return answer;
}