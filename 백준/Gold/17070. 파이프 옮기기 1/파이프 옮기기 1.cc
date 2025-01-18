#include <iostream>

using namespace std;

int N;
int MAP[17][17];
int answer = 0;

//방향: 0가로, 1세로, 2대각선
int dx[] = { 1,0,1 };
int dy[] = { 0,1,1 };

void dfs(int nowY, int nowX, int dir) {

	//종료 조건 
	if (nowY == N - 1 && nowX == N - 1) {
		answer++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		int nx = dx[i] + nowX;
		int ny = dy[i] + nowY;

		if (dir == 0 && i == 1) continue; //현재 방향이 가로, 다음 방향이 세로인경우 불가
		if (dir == 1 && i == 0) continue; //현재 방향이 세로, 다음 방향이 가로이면 불가

		if (nx<0 || ny<0 || nx>N - 1 || ny >N - 1) continue; //범위를 벗어나면 불가
		if (MAP[ny][nx] == 1) continue; //다음 공간이 벽이면 불가

		//다음 방향이 대각선인 경우
		if (i == 2) {
			//가로, 세로가 벽인경우 불가
			if (MAP[ny - 1][nx] == 1 || MAP[ny][nx - 1] == 1) continue;
		}

		dfs(ny, nx, i);


	}

}



int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}

	dfs(0, 1, 0); //(0,1)에서 가로방향으로 시작 

	cout << answer;

	return 0;
}