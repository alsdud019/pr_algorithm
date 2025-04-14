#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[1001][1001];

int stX, stY;
int visited[1001][1001] = {0,};
int answer[1001][1001] = {0,};

struct Node {
	int y;
	int x;
};

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void bfs(int stX, int stY) {
	queue<Node> q;

	q.push({ stY, stX });
	visited[stY][stX] = 1;
	answer[stY][stX] = 0;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;

			if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1)continue;
			if (visited[ny][nx] == 1) continue;
			if (map[ny][nx] == 0) continue;

			answer[ny][nx] = answer[now.y][now.x] + 1;
			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}

	
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				stX = j;
				stY = i;
			}
			if (map[i][j] == 0) answer[i][j] = 0;
			else answer[i][j] = -1;
		}
	}



	bfs(stX, stY);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}



	return 0;
}