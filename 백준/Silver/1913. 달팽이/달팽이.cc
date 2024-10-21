#include <iostream>

using namespace std;
int N, num;
//위오아왼
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int arr[1001][1001];
int ansX, ansY;

int change_dir(int d) {
	d++;
	if (d > 3) return 0;
	return d;
}

int main() {
	cin >> N>>num;

	int stCol = N / 2;
	int stRow = N / 2;
	int d = 0;

	int idx = 1;
	arr[stCol][stRow] = idx;

	if (idx == num) {
		ansX = stRow;
		ansY = stRow;
	}

	for (int i = 1; i <= N; i++) {
		if (i == N) {
			for (int k = 0; k < N-1; k++) {
				idx++;
				int ny = stCol + dy[d];
				int nx = stRow + dx[d];
				arr[ny][nx] = idx;

				stCol = ny;
				stRow = nx;
				if (idx == num) {
					ansX = nx;
					ansY = ny;
				}
				
			}
			break;
		}
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < i; k++) {
				idx++;
				int ny = stCol + dy[d];
				int nx = stRow + dx[d];
				arr[ny][nx] = idx;

				stCol = ny;
				stRow = nx;
				if (idx == num) {
					ansX = nx;
					ansY = ny;
				}
			}
			d = change_dir(d);

		}
		

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	cout << ansY + 1 << " " << ansX + 1;


	return 0;
}