#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[300001];
int dist[300001];
int N, M, K, X;

void dijkstra(int stNode) {
	for (int i = 1; i <= N; i++) {
		dist[i] = 1e9;
	}
	dist[stNode] = 0;

	queue<int>q;
	q.push(stNode);

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i];

			if (dist[now] + 1 >= dist[next]) continue;
			dist[next] = dist[now] + 1;

			q.push(next);
		}

	}

}

int main() {
	
	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		vec[from].push_back(to);
	}

	dijkstra(X);
	
	vector<int>ans;
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			ans.push_back(i);
			cout << i << '\n';
		}
	}
	
	if (ans.empty()) cout << -1 << '\n';
	return 0;
}