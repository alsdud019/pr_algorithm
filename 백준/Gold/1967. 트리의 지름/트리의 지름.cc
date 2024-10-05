#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Node {
	int to;
	int value;
};
int N;
vector<Node> vec[100001];
int visited[100001];
int MAX = -1;
int max_node;

void dfs(int now, int sum) {

	if (visited[now]) return;

	if (sum > MAX) {
		MAX = sum;
		max_node = now;
	}
	visited[now] = 1;

	for (int i = 0; i < vec[now].size(); i++) {
		Node next_node = vec[now][i];
		int next = next_node.to;
		int next_v = next_node.value;

		//if (visited[next]) continue;
		//visited[next] = 1;
		dfs(next, sum + next_v);
		//visited[next] = 0;
	}	
}

int main() {
	cin >> N;

	for (int i = 0; i < N-1; i++) {
		int from, to, v;
		cin >> from >> to >> v;
		vec[from].push_back({ to,v });
		vec[to].push_back({ from,v });
	}

	dfs(1,0);

	memset(visited, 0, sizeof(visited));
	MAX = -1;
	dfs(max_node, 0);

	cout << MAX;


	return 0;
}