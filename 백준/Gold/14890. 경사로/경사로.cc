#include<iostream>
#include <cstring>

using namespace std;
int N, L;
int MAP1[101][101];
int MAP2[101][101];
int cnt;

void init() {
	cnt = 0;
	memset(MAP1, 0, sizeof(MAP1));
	memset(MAP2, 0, sizeof(MAP2));
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP1[i][j];
			MAP2[j][i] = MAP1[i][j];
		}
	}
}

void check(int MAP[][101]) {
	//가로줄 하나 
	for (int i = 0; i < N; i++) {
		bool flag = true;
		int brige[101] = { 0, };
		for (int j = 0; j < N - 1; j++) {

			// 다음칸과 1초과 차이날 때
			if (abs(MAP[i][j] - MAP[i][j + 1]) > 1) {
				flag = false;
				break;
			}

			//다음칸이 현재보다 1 높을 때 
			if (MAP[i][j + 1] - MAP[i][j] == 1) {
				// 설치 안되는 경우
				int first=MAP[i][j];
				for (int k = j; k > j - L; k--) {
					if (k < 0 || MAP[i][k] != first || brige[k]) {
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}

			//다음칸이 현재 칸보다 낮을 때, 현재칸이 1칸 높을때 
			if (MAP[i][j] - MAP[i][j + 1] == 1) {
				int first = MAP[i][j+1];
				for (int k = j + 2; k < j + L + 1; k++) {
					//설치 불가능한 경우
					if (k > N - 1 || first != MAP[i][k]) {
						flag = false;
						break;
					}
				}
				if (!flag) break;
				else {
					brige[j+L] = 1;
				}
			}

		}
		if (flag) cnt++;
	}
}

void Solution() {
	check(MAP1);
	check(MAP2);
	cout << cnt;
}

int main() {

	init();
	Solution();

	return 0;
}