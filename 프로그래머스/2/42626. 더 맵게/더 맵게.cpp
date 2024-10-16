#include <string>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<> > pq(scoville.begin(), scoville.end());
    bool flag=true;
    while(1){
        
        if (pq.top()>=K || pq.size()<0) break;
        if (pq.size()<2 && pq.top()<K){
            flag=false;
            break;
        }
        answer++;
        int first=pq.top(); pq.pop();
        int second=pq.top(); pq.pop();
        
        int new_num=first+second*2;
        pq.push(new_num);
            
    }
    if (flag==false) return -1;
    return answer;
}