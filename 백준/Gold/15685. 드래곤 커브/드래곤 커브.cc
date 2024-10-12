#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int N;
int MAP[101][101];
vector<int>direction;

int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 };
int cnt=0;
int x, y, d, g;


void draw() {
	//역순으로 
	for (int i = direction.size() - 1; i >= 0; i--) {
		int nd = (direction[i] + 1) % 4;
		x += dx[nd];
		y += dy[nd];
		MAP[y][x] = 1;
		direction.push_back(nd);
	}

}

void cnt_square() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (MAP[i][j]==1 && MAP[i][j + 1]==1&& MAP[i + 1][j]==1 && MAP[i + 1][j + 1]==1) {
				cnt++;
			}
		}
	}
}

void Solution() {

	for (int i = 0; i < N; i++) {

		cin >> x >> y >> d >> g;

		direction.clear();

		//0세대
		direction.push_back(d);
		MAP[y][x] = 1;
		x += dx[d];
		y += dy[d];
		MAP[y][x] = 1;

		for (int i = 0; i < g; i++) {
			draw();
		}
	}
	cnt_square();
	cout << cnt;
}


int main() {
	cin >> N;

	Solution();

	return 0;
}