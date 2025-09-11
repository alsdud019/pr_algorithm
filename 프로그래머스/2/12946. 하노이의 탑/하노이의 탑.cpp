#include <string>
#include <vector>

using namespace std;

void hanoi(vector<vector<int>> &answer, int n, int start, int tmp, int end){
    
    if (n==1){
        answer.push_back({start, end});
        return ;
    }
    
    hanoi(answer, n-1, start, end, tmp);
    answer.push_back({start, end});
    hanoi(answer, n-1, tmp, start, end);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    hanoi(answer, n, 1,2,3);
    
    return answer;
}