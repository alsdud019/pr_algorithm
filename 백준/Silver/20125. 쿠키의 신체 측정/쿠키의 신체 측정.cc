#include <iostream>

using namespace std;
int map[1001][1001];

bool check(int y, int x) {
	if (map[y - 1][x] == '*' && map[y + 1][x] == '*' && map[y][x - 1] == '*' && map[y][x + 1] == '*') return true;
	else return false;
}

int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			map[i][j] = str[j];
		}
	}

	//심장 위치 확인하기
	int heart_y, heart_x;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check(i, j)) {
				heart_y = i;
				heart_x = j;
			}
		}
	}

	//왼쪽팔 개수 
	int arm_left=0;
	for (int i = heart_x - 1; i >= 0; i--) {
		if (map[heart_y][i] == '*') arm_left++;
	}

	//오른팔 개수
	int arm_right=0;
	for (int i = heart_x + 1; i <= N - 1; i++) {
		if (map[heart_y][i] == '*') arm_right++;
	}

	//허리 개수 
	int middle = 0;
	for (int i = heart_y + 1; i <= N - 1; i++) {
		if (map[i][heart_x] == '*') middle++;
	}

	int lag_left_y = heart_y + middle + 1;
	int lag_left_x = heart_x - 1;

	int lag_right_y = heart_y + middle + 1;
	int lag_right_x = heart_x + 1;

	//왼쪽 다리 개수 
	int lag_left = 0;
	for (int i = lag_left_y; i <= N - 1; i++) {
		if (map[i][lag_left_x] == '*') lag_left++;
	}

	//오른쪽 다리 개수 
	int lag_right = 0;
	for (int i = lag_right_y; i <= N - 1; i++) {
		if (map[i][lag_right_x] == '*') lag_right++;
	}

	cout << heart_y+1 << " " << heart_x+1 << '\n';
	cout << arm_left << " " << arm_right << " " << middle << " " << lag_left << " " << lag_right;

	return 0;
}