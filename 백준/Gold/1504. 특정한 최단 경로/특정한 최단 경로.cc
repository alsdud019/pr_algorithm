#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
struct Node {
	int to;
	int w;

};
vector<Node> vec[801];

int u, v;


long long dijkstra(int stNode, int endNode) {

	int dist[801];
	for (int i = 1; i <= N; i++) {
		dist[i] = 1e9;
	}

	dist[stNode] = 0;
	queue<int> q;

	q.push(stNode);

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i].to;
			int cost = vec[now][i].w;

			if (dist[next] < dist[now] + cost) continue;

			dist[next] = dist[now] + cost;
			q.push(next);
		}
	}


	return dist[endNode];
}


int main() {

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, w;
		cin >> from >> to >> w;

		vec[from].push_back({ to, w });
		vec[to].push_back({ from, w });

	}

	cin >> u >> v;

	long long case1, case2;

	case1=dijkstra(1,u)+dijkstra(u,v)+dijkstra(v,N);

	case2= dijkstra(1, v) + dijkstra(v, u) + dijkstra(u, N);

	if (case1 >= 1e9 && case2 >= 1e9) {
		cout << -1 << endl;
		return 0;
	}

	else cout << min(case1, case2);


	return 0;
}