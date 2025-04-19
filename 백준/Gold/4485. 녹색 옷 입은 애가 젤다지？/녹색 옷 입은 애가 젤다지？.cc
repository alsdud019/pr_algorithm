#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[127][127] = { 0, };
int visited[127][127] = { 0, };

int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

struct Node {
	int y;
	int x;
};

int dijkstra(int stY, int stX, int endY, int endX, int N) {
	
	queue<Node> q;

	q.push({ stY, stX });
	visited[stY][stX] = map[stY][stX];

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;

			if (ny<0 || nx<0 || ny>N - 1 || nx>N - 1) continue;
			
			if (visited[ny][nx] <= visited[now.y][now.x] + map[ny][nx])continue;

			visited[ny][nx] = visited[now.y][now.x] + map[ny][nx];
			q.push({ ny,nx });

		}
	}

	return visited[endY][endX];

}

void init(int N) {
	memset(map, 0, sizeof(map));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 1e9;
		}
	}

}

int main() {
	int i = 1;

	while (1) {
		int N;
		cin >> N;

		if (N == 0) break;

		init(N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		cout<<"Problem "<<i<<": "<<dijkstra(0, 0, N - 1, N - 1, N)<<'\n';
		i++;
	}


	return 0;
}