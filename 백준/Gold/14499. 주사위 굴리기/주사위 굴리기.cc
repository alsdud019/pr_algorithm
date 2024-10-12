#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int N, M, x, y, K;
int MAP[21][21];
vector<int> input;
int dice[7];


void init() {
	memset(MAP, 0, sizeof(MAP));
	input.clear();
	memset(dice, 0, sizeof(dice));

	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		input.push_back(num);
	}

	for (int i = 1; i <= 6; i++) {
		dice[i] = 0;
	}

}
void rotate(int d) {
	int temp = dice[1];
	if (d == 1) { //동
		y++;
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = temp;
	}
	else if (d == 2) { //서
		y--;
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = temp;
	}
	else if (d == 3) { //북
		x--;
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = temp;
	}
	else if (d == 4) { //남
		x++;
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = temp;
	}
}
bool check(int d) {
	if (d == 1) {
		if (y == M - 1) return false;
	}
	else if (d == 2) {
		if (y == 0) return false;
	}
	else if (d == 3) {
		if (x == 0) return false;
	}
	else if (d == 4) {
		if (x == N-1) return false;
	}
	return true;
}

void Solution() {
	for (int i = 0; i < input.size(); i++) {

		if(check(input[i])==false) continue;

		rotate(input[i]);
		if (MAP[x][y] == 0) {
			MAP[x][y] = dice[6];
		}
		else {
			dice[6] = MAP[x][y];
			MAP[x][y] = 0;
		}
		cout << dice[1] << '\n';
	}
}

int main() {
	init();
	Solution();
	return 0;
}