#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
vector<int> stack;

int solution(vector<int> order) {
    int answer = 0;

    int idx=0;
    
    for (int i=1; i<=order.size(); i++){
        int now=i;
        stack.push_back(now);
        
        while (!stack.empty() && stack.back()==order[idx]){
            stack.pop_back();
            answer++;
            idx++;
        }
        
    }
        

    
    
    return answer;
}