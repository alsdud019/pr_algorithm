#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    int jang=hp/5;
    answer+=jang;
    hp%=5;
    
    int beoung=hp/3;
    answer+=beoung;
    answer+=hp%3;
    
    return answer;
}