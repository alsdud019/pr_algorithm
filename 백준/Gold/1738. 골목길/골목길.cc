#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
struct Node {
	int to;
	int cost;
};

vector<Node> vec[101];
vector<int> rev[101];
int dist[101];
int answer[101];
int able[101] = {0,};

void check_bfs() {
	queue<int> q;
	q.push(N);

	while(!q.empty()) {
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

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		vec[from].push_back({ to, cost });
		rev[to].push_back(from);
	}

	check_bfs();

	for (int i = 1; i <= N; i++) {
		dist[i] = -1e9;
	}

	dist[1] = 0;

	for (int i = 0; i < N; i++) {

		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < vec[j].size(); k++) {
				int next = vec[j][k].to;
				int cost = vec[j][k].cost;

				if (dist[next] < dist[j] + cost) {
					dist[next] = dist[j] + cost;
					//cout << "j=" << j << " next=" << next << endl;
					answer[next] = j;
				}
			}
		}
	}

	for (int j = 1; j <= N; j++) {
		for (int k = 0; k < vec[j].size(); k++) {
			int next = vec[j][k].to;
			int cost = vec[j][k].cost;

			if (dist[next] < dist[j] + cost) {
				if (able[next]) {
					cout << -1 << endl;
					return 0;
				}
				
			}
		}
	}

	vector<int> ans;
	
	int now = N;
	while(1) {
		ans.push_back(now);
		if (now == 1) break;
		now = answer[now];
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
	

	return 0;
}