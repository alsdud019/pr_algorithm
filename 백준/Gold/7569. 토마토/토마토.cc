#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int N, M, H;
int arr[101][101][101] = {0,};
int visited[101][101][101] = { 0, };
struct Node {
	int z;
	int y;
	int x;
};

queue<Node> q;
int dz[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,0,0,1,-1 };
int dx[] = { 0,0,-1,1,0,0 };

int day = -1e9;
int check = 0;

void BFS() {

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = dz[i] + now.z;
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;

			if (nx<0 || ny<0 || nz<0 || nx>N - 1 || ny>M - 1 || nz>H - 1) continue;
			if (arr[nz][ny][nx] != 0) continue;
			if (visited[nz][ny][nx] != 0) continue;

			visited[nz][ny][nx] = visited[now.z][now.y][now.x] + 1;
			q.push({ nz, ny, nx });
			arr[nz][ny][nx] = 1;

			day = max(visited[nz][ny][nx], day);
		}
	}


}


int main() {

	cin >> N >> M >> H;

	int zero = 0;

	for (int h = 0; h < H; h++) {
		for (int m = 0; m < M; m++) {
			for (int n = 0; n < N; n++) {
				int tomato;
				cin >> tomato;
				arr[h][m][n] = tomato;
				if (tomato == 1) {
					q.push({ h,m,n });
					visited[h][m][n] = 1;
				}
				if (tomato == 0) {
					zero++;
				}
			}
		}
	}

	if (zero == 0) {
		cout << 0 << '\n';
		return 0;
	}

	BFS();

	for (int h = 0; h < H; h++) {
		for (int m = 0; m < M; m++) {
			for (int n = 0; n < N; n++) {
				if (arr[h][m][n] == 0) {
					cout << -1 << '\n';
					return 0;
				}
			}
		}
	}
	//if (zero == check) {
	//	cout << -1 << '\n';
	//	return 0;
	//}

	cout << day-1 << '\n';


	return 0;
}