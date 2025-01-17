#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
struct Node {
	int to;
	int w;
};
vector<Node> vec[101];
int S, E;

int Sdist[101];
int Edist[101];

void dijkstra(int stNode, int arr[101]) {
	for (int i = 1; i <= N; i++) arr[i] = 1e9;

	arr[stNode] = 0;

	queue<int> q;
	q.push(stNode);

	while (!q.empty()) {

		int now = q.front(); q.pop();


		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i].to;
			int cost = vec[now][i].w;

			if (arr[next] < arr[now] + cost) continue;

			arr[next] = arr[now] + cost;

			q.push(next);
		}
	}

}

int main() {

	cin >> N >> M;

	//양방향 입력받기 
	for (int i = 0; i < M; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		vec[from].push_back({ to, w });
		vec[to].push_back({ from, w });
	}

	cin >> S >> E;

	dijkstra(S, Sdist);
	dijkstra(E, Edist);

	int min_time = 1e9;
	int min_dist = 1e9;
	int answer = -1;

	for (int i = 1; i <= N; i++) {
		if (S == i || E == i) continue;
		min_time = min(Edist[i] + Sdist[i], min_time);
	}

	for (int k = N; k >= 1; k--) {
		if (k == S || k == E) continue;
		if (Edist[k] + Sdist[k] != min_time) continue;
		if (Sdist[k] > Edist[k]) continue;
		if (min_dist >= Sdist[k]) {
			min_dist = Sdist[k];
			answer = k;
		}
	}

	cout << answer;
	return 0;
}