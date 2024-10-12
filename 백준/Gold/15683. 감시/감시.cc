#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int N, M;
int MAP[9][9];

int camera;
int MIN;

int dy[] = {-1,0,1,0};
int dx[] = {0,-1,0,1};

struct Node{
	int value;
	int x;
	int y;
};

void init() {
	memset(MAP, 0, sizeof(MAP));
	//memset(C_MAP, 0, sizeof(C_MAP));
	camera = 0;
	MIN = 1e9;
}
vector<Node> cameras;


void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (1<=MAP[i][j] && MAP[i][j] <=5) {
				camera++;
				cameras.push_back({ MAP[i][j], j,i });
			}
		}
	}
}

void marking(int nx, int ny, int dir) {
	dir %= 4;
	while (true) {
		nx += dx[dir];
		ny += dy[dir];
		if (nx<0 || ny<0 || ny>N - 1 || nx>M - 1) return;
		if (MAP[ny][nx] == 6) return;
		if (MAP[ny][nx] != 0) continue;
		MAP[ny][nx] = '#';
	}
}

int calcul() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void dfs(int idx) {
	//종료조건
	if (idx == camera) {
		int re=calcul();
		if (re < MIN) MIN = re;
		return;
	}

	Node now = cameras[idx];
	int x = now.x;
	int y = now.y;
	int camera_num = now.value;

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		C_MAP[i][j] = MAP[i][j];
	//	}
	//}
	int C_MAP[9][9];
	
	//하나의 카메라에 대해서 4방향으로 돌려본다. 
	for (int dir = 0; dir < 4; dir++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				C_MAP[i][j] = MAP[i][j];
			}
		}
		if (camera_num == 1) {
			marking(x, y, dir);

		}
		else if (camera_num == 2) {
			marking(x, y, dir);
			marking(x, y, dir + 2);

		}
		else if (camera_num == 3) {
			marking(x, y, dir);
			marking(x, y, dir + 1);

		}
		else if (camera_num == 4) {
			marking(x, y, dir);
			marking(x, y, dir + 1);
			marking(x, y, dir + 2);
		}
		else if (camera_num == 5) {
			marking(x, y, dir);
			marking(x, y, dir + 1);
			marking(x, y, dir + 2);
			marking(x, y, dir + 3);
		}

		dfs(idx + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				MAP[i][j] = C_MAP[i][j];
			}
		}
	}

}

void Solution() {
	dfs(0);
	cout << MIN;
}

int main() {
	init();
	input();
	Solution();
	return 0;
}