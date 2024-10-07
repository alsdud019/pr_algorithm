#include <iostream>
#include <queue>

using namespace std;

int N, M;
int ry, rx;
int d;
int MAP[51][51];

int dy[] = {-1,0,1,0};
int dx[] = { 0,1,0,-1 };
int cnt = 0;

void Solution() {
	
	while (1) {
		//1번 현재 위치 청소 
		if (MAP[ry][rx] == 0) {
			MAP[ry][rx] = 8;
			cnt++;
		}
		bool isclean = true;
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + ry;
			int nx = dx[i] + rx;
			if (ny<0 || nx<0 || ny>N - 1 || nx>M - 1)continue;
			if (MAP[ny][nx] != 0) continue;

			if (MAP[ny][nx] == 0) {
				isclean = false;
				d = (d + 3) % 4;
				
				//한칸 전진했을 때 청소되지 않은 경우 
				int y = dy[d] + ry;
				int x = dx[d] + rx;
				if (MAP[y][x] == 0) {
					ry = y;
					rx = x;
				}
				break;
			}

		}
		if (isclean) {
			//모두 깨끗하면 후진 
			ry -= dy[d];
			rx -= dx[d];
			if (ry<0 || rx<0 || ry>N - 1 || rx>M - 1)break;
			if (MAP[ry][rx] == 1) break;
		}
	}


}


int main() {
	cin >> N >> M;
	cin >> ry >> rx;
	cin >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}

	Solution();

	cout << cnt;

	return 0;
}