#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
struct Node {
	int to;
	int w;
};
vector<Node> vec[1001];

int dist[1001];
int from[1001];


void dijkstra(int stNode) {

	for (int i = 1; i <= N; i++) {
		dist[i] = 1e9;
	}

	dist[1] = 0;

	queue<int> q;
	q.push(stNode);

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i].to;
			int time = vec[now][i].w;

			if (dist[next] <= dist[now] + time) continue;
			dist[next] = dist[now] + time;
			from[next] = now;

			q.push(next);
		}

		
	}


}


int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, time;
		cin >> from >> to >> time;
		vec[from].push_back({ to, time });
		vec[to].push_back({ from, time });
	}

	dijkstra(1);

	cout << N - 1 << endl;

	for (int i = 2; i <= N; i++) {
		cout << i <<" "<< from[i] << endl;
	}
	

	return 0;
}