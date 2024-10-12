#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int N,M,K;
int MAP[21][21];
int x, y, d;
int dice[7];
int visited[21][21];
int sum;

void init() {
	memset(MAP, 0, sizeof(MAP));
	memset(dice, 0, sizeof(dice));
	x = 0;
	y = 0;
	d = 0;
	sum = 0;

}

void input() {
	cin >> N>>M>>K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < 7; i++) dice[i] = i;

}
void move_dice(int d) {
	int temp = dice[1];
	if (d == 0) {
		x++;
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = temp;
	}
	else if (d == 2) {
		x--;
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = temp;
	}
	else if (d == 1) {
		y--;
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = temp;
	}
	else if (d == 3) {
		y++;
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = temp;
	}
}

void rotate(int toggle) {
	//시계방향
	if (toggle) {
		d--;
		if (d < 0) d = 3;
	}
	else {
		d++;
		if (d > 3) d = 0;
	}
}

void check() {
	if (d == 0) {
		if (x == M - 1) {
			d = 2;
		}
	}
	else if (d == 1) {
		if (y == 0) {
			d = 3;
		}
	}
	else if (d == 2) {
		if (x == 0) {
			d = 0;
		}
	}
	else if (d == 3) {
		if (y == N - 1) {
			d = 1;
		}
	}
	
}

struct Node {
	int x;
	int y;
};

int bfs(int stX, int stY) {
	int cnt = 1;
	memset(visited, 0, sizeof(visited));

	queue<Node> q;
	q.push({ stX, stY });
	visited[stY][stX] = 1;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		int dy[4] = {0,0,-1,1};
		int dx[4] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;
			if (ny<0 || nx<0 || ny>N - 1 || nx>M - 1)continue;
			if (visited[ny][nx] == 1) continue;

			if (MAP[ny][nx] == MAP[stY][stX]) {
				visited[ny][nx] = 1;
				q.push({ nx, ny });
				cnt++;
			}
		}
	}

	return cnt * MAP[stY][stX];


}

void Solution() {
	while (K--) {
		check();

		move_dice(d);
		sum += bfs(x, y);

		if (dice[6] > MAP[y][x]) {
			rotate(1);
		}
		else if (dice[6] < MAP[y][x]) {
			rotate(0);
		}
	}
	cout << sum;

}
int main() {
	
	init();
	input();
	Solution();

	return 0;
}