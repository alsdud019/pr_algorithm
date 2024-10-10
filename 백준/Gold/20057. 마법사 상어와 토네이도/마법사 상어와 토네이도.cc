#include <iostream>

using namespace std;
int N;
int MAP[500][500];
int Ty, Tx;
int sum = 0;

int dy[] = { 0,1,0,-1 };
int dx[] = { -1,0,1,0 };

int percent[] = { 5,10,10,7,7,2,2,1,1 };
int py[4][9] = { 
	{0,-1,1,-1,1,-2,2,-1,1},
	{2,1,1,0,0,0,0,-1,-1},
	{0,-1,1,-1,1,-2,2,-1,1},
	{-2,-1,-1,0,0,0,0,1,1} };

int px[4][9] = { 
	{ -2,-1,-1,0,0,0,0,1,1 },
	{0,-1,1,-1,1,-2,2,-1,1},
	{2,1,1,0,0,0,0,-1,-1},
	{0,-1,1,-1,1,-2,2,-1,1} };

int alphaY[] = { 0,1,0,-1 };
int alphaX[] = { -1,0,1,0 };

void spread_morea(int y, int x, int d) {
	int nowY = y + dy[d];
	int nowX = x + dx[d];
	int nowV = MAP[nowY][nowX];
	if (MAP[nowY][nowX] == 0) return;

	for (int i = 0; i < 9; i++) {
		int value = (nowV * percent[i]) /100;
		int ny = nowY + py[d][i];
		int nx = nowX + px[d][i];

		if (ny<0 || nx <0 || ny>N - 1 || nx>N - 1) sum += value;
		else MAP[ny][nx] += value;

		MAP[nowY][nowX] -= value;
	}
	int ay = nowY + alphaY[d];
	int ax = nowX + alphaX[d];
	if (ax<0 || ay<0 || ay>N - 1 || ax>N - 1) {
		sum += MAP[nowY][nowX];
	}
	else MAP[ay][ax] += MAP[nowY][nowX];

	MAP[nowY][nowX] = 0;

}

int change_direction(int d) {

	d += 1;
	if (d > 3) d = 0;
	return d;

}

void Rotation()
{
	int d = 0; //왼쪽 방향으로 시작 
	int level = 1;
	while (true) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < level; j++) {
				spread_morea(Ty, Tx, d);
				Ty += dy[d];
				Tx += dx[d];
				
			}
			d = change_direction(d);

		}
		level++;

		if (level == N) {
			for (int i = 0; i < level -1 ; i++) {
				spread_morea(Ty, Tx, d);
				Ty += dy[d];
				Tx += dx[d];

			}

			break;
		}

	}
}

void Solution() {
	Rotation();
}


int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
		
	}

	Ty = N / 2;
	Tx = N / 2;


	Solution();

	cout << sum;

	return 0;
}