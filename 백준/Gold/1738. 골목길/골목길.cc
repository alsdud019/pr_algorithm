#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;

struct Node {
	int to;
	int cost;
};

vector<Node> vec[101];
int D[101];
int track[101];
vector<int> rev[101];
int able[101] = {0,};

void bfs(int now) {
	queue<int> q;
	q.push(now);
	able[now] = 1;

	while (!q.empty()) {

		int now = q.front(); q.pop();

		for (int i = 0; i < rev[now].size(); i++) {
			int next = rev[now][i];
			if (able[next]) continue;

			able[next] = 1;
			q.push(next);
		}
	}

	
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		vec[from].push_back({ to, w });
		rev[to].push_back(from);

	}

	bfs(n);

	for (int i = 1; i <= n; i++) {
		D[i] = -1e9;
	}

	D[1] = 0;

	//n-1번 반복
	for (int i = 1; i <= n - 1; i++) {

		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < vec[j].size(); k++) {
				int now = j;
				int next = vec[now][k].to;
				int cost = vec[now][k].cost;

				if (D[now] + cost <= D[next]) continue;
				D[next] = D[now] + cost;
				//cout <<now << " " << next << endl;
				track[next] = now;
			}
		}
	}

	//음수사이클 확인 
	for (int j = 1; j <= n; j++) {
		for (int k = 0; k < vec[j].size(); k++) {
			int now = j;
			int next = vec[now][k].to;
			int cost = vec[now][k].cost;

			if (D[now] + cost <= D[next]) continue;
			if (able[next]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	int ago = n;
	vector<int> answer;

	while (1) {
		answer.push_back(ago);
		if (ago == 1) break;
		ago = track[ago];
	}


	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}

	return 0;
}