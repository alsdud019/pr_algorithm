#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    
    for (int i=0; i<enemy.size(); i++){
        if (n>=enemy[i]){
            n-=enemy[i];
            pq.push(enemy[i]);
        }
        else{
            if (k<=0) break;
            if (!pq.empty() && pq.top() > enemy[i]){
                n+=pq.top();
                pq.pop();
                
                n-=enemy[i];
                pq.push(enemy[i]);
            }
            k--;
        }    
        answer=i;
    }
    
    return answer+1;
}