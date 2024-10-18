#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    int ans = 0;
    int weightSum = 0; // 다리 위의 트럭 무게의 합
    for(int i = 0; i < truck_weights.size(); i++) {
        while(true) {
            if(q.size() == bridge_length) {
                weightSum -= q.front(); // 맨 앞의 트럭 제거
                q.pop();
            }
            if(truck_weights[i] + weightSum <= weight) {
                break;
            }
            q.push(0); // 무게가 L을 넘는 경우
            ans++;
        }
        q.push(truck_weights[i]);
        weightSum += truck_weights[i];
        ans++;
    }

    
    return ans+bridge_length;
}