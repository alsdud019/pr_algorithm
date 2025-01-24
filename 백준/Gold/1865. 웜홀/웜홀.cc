#include <iostream>
#include <vector>

using namespace std;

int TC;
int N, M, W;

struct Node {
	int to;
	int cost;
};

void bellman_ford(vector<Node> vec[501]) {
	
	int dist[501];
	
	for (int i = 0; i < N; i++) {
		dist[i] = 1e9;
	}

	dist[1] = 0;

	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < vec[j].size(); k++) {
				int to = vec[j][k].to;
				int cost = vec[j][k].cost;

				if (dist[to] > dist[j] + cost) {
					dist[to] = dist[j] + cost;
				}

			}
		}
	}

	for (int j = 1; j <= N; j++) {
		for (int k = 0; k < vec[j].size(); k++) {
			int to = vec[j][k].to;
			int cost = vec[j][k].cost;

			if (dist[to] > dist[j] + cost) {
				cout << "YES" << '\n';
				return;
			}

		}
	}

	cout << "NO" << '\n';
}

int main() {

	cin >> TC;
	while (TC--) {

		
		cin >> N >> M >> W;

		vector<Node> vec[501];

		for (int i = 0; i < M; i++) {
			int from, to, w;
			cin >> from >> to >> w;
			vec[from].push_back({ to, w });
			vec[to].push_back({ from, w });
		}

		for (int i = 0; i < W; i++) {
			int from, to, w;
			cin >> from >> to >> w;
			vec[from].push_back({ to, -w });
		}

		bellman_ford(vec);

	}


	return 0;
}