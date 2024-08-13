#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int mok=score.size()/m;
    sort(score.rbegin(),score.rend());
    
    
    for (int i=1; i<=mok; i++){
        answer+=score[i*m-1] * m;
    }
    return answer;
} 