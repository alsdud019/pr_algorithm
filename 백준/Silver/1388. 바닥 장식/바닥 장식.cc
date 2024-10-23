#include <iostream>

using namespace std;

int N, M;

char arr[51][51];
//오, 아
int dy[] = { 0,1 };
int dx[] = { 1,0 };

int main() {

	int cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char now = arr[i][j];
			if (now == '.') continue;
			int x = j;
			int y = i;

			if (now == '-') {
				while (1) {
					int ny = y + dy[0];
					int nx = x + dx[0];
					if (ny<0 || nx<0 || ny>N - 1 || nx>M - 1) break;
					if (arr[ny][nx] == '-') {
						arr[ny][nx] = '.';
						y = ny;
						x = nx;
					}

					else break;
				}
			}
			else if (now == '|') {
				while (1) {
					int ny = y + dy[1];
					int nx = x + dx[1];
					if (ny<0 || nx<0 || ny>N - 1 || nx>M - 1) break;
					if (arr[ny][nx] == '|') {
						arr[ny][nx] = '.';
						y = ny;
						x = nx;
					}
					else break;
				}
			}
			arr[i][j] = '.';
			cnt++;

		}
	}

	cout << cnt;

	return 0;
}