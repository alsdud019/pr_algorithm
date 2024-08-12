#include <string>
#include <vector>

using namespace std;

int acksu(int num){
    int acksu_number=0;
    for (int i=1; i<=num/2; i++){
        if (num%i==0) acksu_number++;
    }
    return acksu_number+1;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for (int i=1; i<=number; i++){
        int re=acksu(i);
        if (re>limit) answer+=power;
        else answer+=re;
    }
    
    return answer;
}