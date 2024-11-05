#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
struct Node {
	int y;
	int x;
};
int m;
int arr[301][301] = {0,};
int dy[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 1,2,2,1,-1,-2,-2,-1 };

int BFS(int stY, int stX, int endY, int endX) {
	queue<Node> q;

	q.push({ stY, stX });

	while (!q.empty()) {

		Node now = q.front(); q.pop();

		int nowY = now.y;
		int nowX = now.x;

		if (nowX == endX && nowY == endY) break;

		for (int i = 0; i < 8; i++) {
			int ny = nowY + dy[i];
			int nx = nowX + dx[i];

			if (nx<0 || ny<0 || ny>m - 1 || nx>m - 1) continue;
			if (arr[ny][nx] != 0) continue;

			q.push({ ny, nx });
			arr[ny][nx] = arr[nowY][nowX] + 1;

		}

	}

	return arr[endY][endX];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> m;
		memset(arr, 0, sizeof(arr));

		int stY, stX, endY, endX;
		cin >> stY >> stX >> endY >> endX;

		cout<<BFS(stY, stX, endY, endX)<<'\n';

	}

	return 0;
}