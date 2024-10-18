#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, w, L;

vector<int> vec;
int sum = 0;
queue<int> q;
int answer = 0;

void Solution() {
	for (int i = 0; i < n; i++) {
		while (1) {
			if (q.size() == w) {
				sum -= q.front();
				q.pop();
			}
			if (sum + vec[i] <= L)break;
			q.push(0);
			answer++;
		}
		
		q.push(vec[i]);
		sum += vec[i];
		answer++;

	}
}


int main() {

	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	Solution();

	cout << answer + w;


	return 0;
}