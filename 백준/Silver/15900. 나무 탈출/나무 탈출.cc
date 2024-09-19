#include <iostream>
#include <vector>

using namespace std;

int N; 
vector<int> vec[500001];
int visited[500001] = { 0, };
int total = 0;

void DFS(int node, int level) {
	if (node != 1 && vec[node].size() == 1) {
		total += level;
		return;
	}

	for (int i = 0; i < vec[node].size(); i++) {
		int next = vec[node][i];
		if (visited[next] == 1) continue;
		visited[next] = 1;
		DFS(next, level + 1);
		visited[next] = 0;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int from, to;
		cin >> from >> to;
		vec[from].push_back(to);
		vec[to].push_back(from);
	}
	visited[1] = 1;
	DFS(1, 0);

	if (total % 2 == 0) cout << "No" << endl;
	else cout << "Yes" << endl;


	return 0;
}