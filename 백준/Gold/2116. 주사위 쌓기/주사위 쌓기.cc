#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dices[10001][7] = {0,};


int cross(int under_idx) {
	if (under_idx == 0) {
		return 5;
	}
	else if (under_idx == 1) {
		return 3;
	}
	else if (under_idx == 2) {
		return 4;
	}
	else if (under_idx == 3) {
		return 1;
	}
	else if (under_idx == 4) {
		return 2;
	}
	else if (under_idx == 5) {
		return 0;
	}
}

void copy(int A[10001][7], int B[10001][7]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 6; j++) {
			B[i][j] = A[i][j];
		}
	}
}

int Solution(int under_idx) {
	//첫번째 주사위 윗면
	int up_idx = cross(under_idx);
	int num = dices[0][up_idx];


	int cp_dices[10001][7] = { 0, };
	copy(dices, cp_dices);

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 6; j++) {
			int now = dices[i][j];
			//아랫면이 이전 주사위의 윗면과 같다면
			if (now == num) {
				up_idx = cross(j);
				under_idx = j;
				num = dices[i][up_idx];

				cp_dices[i][j] = 0;
				cp_dices[i][up_idx] = 0;
				break;
			}
		}

		int m = -1e9;
		for (int j = 0; j < 6; j++) {
			m = max(m, cp_dices[i][j]);
		}

		answer += m;
	}

	//cout << answer<<'\n';
	return answer;

}

int main() {

	cin >> N;
	//주사위 번호
	for (int i = 0; i < N; i++) {
		//주사위 1개 당 숫자 위치 
		for (int j = 0; j < 6; j++) {
			cin >> dices[i][j];
		}
	}

	int MAX = -1e9;

	//첫번째 주사위 아랫면에 따른 최댓값 구하기 
	for (int i = 0; i < 6; i++) {
		int under = dices[0][i];
		int answer= Solution(i);
		MAX = max(answer, MAX);
	}

	cout << MAX << '\n';

	return 0;
}