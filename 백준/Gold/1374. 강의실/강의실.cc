#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {

	int N;
	cin >> N;

	vector<pair<int,int>> vec;
	priority_queue<int, vector<int>, greater<int>> pq;
	int answer = 1;

	for (int i = 0; i < N; i++) {
		int num, start, end;

		cin >> num >> start >> end;
		
		vec.push_back({ start, end });
	}

	sort(vec.begin(), vec.end());

	
	for (int i = 0; i < vec.size(); i++) {
		int start = vec[i].first;
		int end = vec[i].second;

		if (!pq.empty()) {
			if (pq.top() > start) {
				answer++;
			}
			else {
				pq.pop();
			}
		}

		//현재 진행중인 강의 끝나는 시간 삽입. 
		pq.push({ end });
	}


	cout << answer;

	return 0;
}