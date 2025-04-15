#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, V;
vector<int> vec[1002];
int used[1001] = { 0, };
int visited[1002] = { 0, };

void dfs(int now) {

	cout << now << " ";

	for (int i = 0; i < vec[now].size(); i++) {
		int next = vec[now][i];

		if (used[next] == 1) continue;
		used[next] = 1;
		
		dfs(next);
	}
}

void bfs(int stNode) {
	queue<int> q;
	q.push(stNode);

	visited[stNode] = 1;
	cout << stNode << " ";

	while (!q.empty()) {
		int now = q.front(); q.pop();
	

		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i];
			if (visited[next] == 1)continue;

			q.push(next);
			visited[next] = 1;
			cout << next << " ";

		}

	}


}

int main() {

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		vec[from].push_back(to);
		vec[to].push_back(from);
	}

	for (int i = 1; i <= N; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	used[V] = 1;
	dfs(V);
	cout << '\n';
	bfs(V);



	return 0;
}