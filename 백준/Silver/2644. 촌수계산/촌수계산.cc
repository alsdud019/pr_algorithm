#include <iostream>
#include <vector>

using namespace std;
vector<int> graph[101];
int visited[101] = {0,};
int me, you;
int answer = -1;
bool flag = false;

void DFS(int now, int level) {
	if (flag) {
		return;
	}

	//cout << level << " " << now << '\n';

	if (now == you) {
		answer = level;
		flag = true;
		return;
	}

	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (visited[next]) continue;

		visited[next] = 1;
		DFS(next, level + 1);
		visited[next] = 0;
	}

}

int main() {

	int N;
	cin >> N;

	cin >> me >> you;

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	visited[me] = 1;
	DFS(me, 0);

	cout << answer << '\n';


	return 0;
}