#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> vec[200001];
map<int, int> m;

int N, M, R;
int visited[200001];
int level = 1;
int result[100001] = {0,};

void DFS(int now) {

	//cout << level<<" "<<now << endl;
	//m.insert({ now, level });
	result[now] = level++;

	for (int i = 0; i < vec[now].size(); i++) {
		int next = vec[now][i];
		if (visited[next]==1) continue;
		visited[next] = 1;
		DFS(next);

	}
}

int main() {


	cin >> N >> M >> R;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		vec[from].push_back(to);
		vec[to].push_back(from);
	}

	for (int i = 1; i <= N; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	visited[R] = 1;

	DFS(R);

	for (int i = 1; i <=N; i++) {
		cout << result[i]<<'\n';
	}




	return 0;
}