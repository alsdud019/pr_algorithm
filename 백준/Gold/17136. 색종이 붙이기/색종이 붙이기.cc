#include <iostream>

using namespace std;

int map[11][11];
int used[5] = {5,5,5,5,5};

bool check(int k, int y, int x) {

	if (y + k > 9 || x + k > 9) return false;

	for (int i = y; i <= y + k; i++) {
		for (int j = x; j <= x + k; j++) {
			if (map[i][j] != 1) return false;
		}
	}
	return true;
}

void color(int k, int y, int x, int c) {
	for (int i = y; i <= y + k; i++) {
		for (int j = x; j <= x + k; j++) {
			map[i][j] = c;
		}
	}
}

int result = 1e9;

bool fill_zero() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] != 0) return false;
		}
	}
	return true;
}

void backtracking(int cnt) {

	if (fill_zero()) {
		result = min(cnt, result);
		return;
	}

	if (cnt > result) return;


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 1) {
				for (int k = 4; k >=0; k--) {
					if (used[k]>0 && check(k, i, j)) {

						used[k]--;

						color(k, i, j,0);
						backtracking(cnt+1);

						used[k]++;
						color(k, i, j, 1);



					}
				}
				return;
			}
		}
	}
}

int main() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
		}
	}

	backtracking(0);

	cout << (result==1e9 ? -1 : result);


	return 0;
}