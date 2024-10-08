#include <iostream>
#include <vector>

using namespace std;
int R, C;
char MAP[11][11];

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };
vector<pair<int, int>> sea;

int main() {

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (MAP[i][j] != '.') {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int ny = dy[k] + i;
					int nx = dx[k] + j;
					if (nx<0 || ny<0 || nx>C - 1 || ny>R - 1) {
						cnt++;
						continue;
					}
					if (MAP[ny][nx] == '.') cnt++;
				}

				if (cnt == 3 || cnt == 4) sea.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < sea.size(); i++) {
		MAP[sea[i].first][sea[i].second]='.';

	}

	int x_min = 1e9;
	int x_max = -1e9;
	int y_min = 1e9;
	int y_max = -1e9;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (MAP[i][j] == 'X') {
				x_min = min(x_min, j);
				x_max = max(x_max, j);
				y_min = min(y_min, i);
				y_max = max(y_max, i);
			}
		}
	}
	for (int i = y_min; i <= y_max; i++) {
		for (int j = x_min; j <= x_max; j++) {
			cout << MAP[i][j];
		}
		cout <<  '\n';
	}


	return 0;
}