#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;
int N, M, R;
vector<int> vec[100001];
int visited[100001]={0,};

unordered_map <int, int>m;

void BFS(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	int level = 1;

	while (!q.empty()) {
		
		int now = q.front(); q.pop();
		//cout << now << " " << level << endl;
		m.insert({ now,level++ });

		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i];
			if (visited[next] == 1) continue;

			q.push(next);
			visited[next] = 1;
		}


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

	BFS(R);

	for (int i = 1; i <= N; i++) {
		cout << m[i] << '\n';
	}

	return 0;
}