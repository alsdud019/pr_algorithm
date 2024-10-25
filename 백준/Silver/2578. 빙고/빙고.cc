#include<iostream>
#include <vector>

using namespace std;

struct who {
	int y;
	int x;
};
int bingo[6][6];
vector<who> bingos [26];
int cnt = 0;

void check(int now) {
	int y = bingos[now][0].y;
	int x = bingos[now][0].x;

	//빙고판 체크하기 
	bingo[y][x] = 1;

	//같은 행이 빙고인지
	int col_flag = true;
	for (int i = 0; i < 5; i++) {
		if (bingo[y][i] == 0) {
			col_flag = false;
			break;
		}
	}
	if (col_flag) cnt++;

	//같은 열이 빙고인지
	int row_flag = true;
	for (int i = 0; i < 5; i++) {
		if (bingo[i][x]==0) {
			row_flag = false;
			break;
		}
	}
	if (row_flag) cnt++;

	//대각선이 빙고인지 확인 
	bool cross_flag1 = true;
	bool cross_flag2 = true;
	if (x == y) {
		for (int i = 0; i < 5; i++) {
			if (bingo[i][i] == 0) {
				cross_flag1 = false;
				break;
			}
		}
	}
	if (x == y && cross_flag1) cnt++;

	if (x + y == 4) {
		for (int i = 0; i < 5; i++) {
			if (bingo[i][4 - i] == 0) {
				cross_flag2 = false;
				break;
			}
		}
	}
	if (x + y == 4 && cross_flag2) cnt++;

}

int main() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int num;
			cin >> num;
			bingos[num].push_back({i, j});
		}
	}

	for (int i = 1; i <= 25; i++) {
		int num;
		cin >> num;
		check(num);
		if (cnt >= 3) {
			cout << i << '\n';

			return 0;
		}
	}

	return 0;
}