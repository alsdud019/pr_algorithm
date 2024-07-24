#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    int cupon=chicken;
    
    while (chicken>=1){
        answer+=cupon/10;
        chicken=cupon/10;
        cupon=chicken+cupon%10;
    }
    

    return answer;
}