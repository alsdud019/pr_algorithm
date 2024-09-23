#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Node;
int Edge;

vector<int> vec[101];
int visited[101] = { 0, };
int total = 0;

void BFS(int node) {
	queue<int> q;

	q.push(node);
	visited[node] = 1;

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i];
			if (visited[next] == 1) continue;
			q.push(next);
			visited[next] = 1;
			total++;

		}
	}
}


int main() {

	cin >> Node >> Edge;
	for (int i = 0; i < Edge; i++) {
		int from, to;
		cin >> from >> to;
		vec[from].push_back(to);
		vec[to].push_back(from);
	}

	BFS(1);
	cout << total;

	return 0;
}