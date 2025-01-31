#include <iostream>

using namespace std;

int game[11];
int MAP[34];
int dir[34];

int horse[4] = { 0, };
int check[34];
int answer = -1e9;

void init() {
	for (int i = 1; i <= 20; i++) {
		MAP[i] = i * 2;
	}
	MAP[22] = 13; MAP[23] = 16; MAP[24] = 19;
	MAP[25] = 25; MAP[26] = 30; MAP[27] = 35;
	MAP[28] = 22; MAP[29] = 24;
	MAP[30] = 28; MAP[31] = 27; MAP[32] = 26;

	dir[5] = 22; dir[10] = 28; dir[15] = 30;
	dir[29] = 25; dir[32] = 25; dir[27] = 20;


}

void dfs(int level, int sum) {

	if (level == 10) {
		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int cur = horse[i];
		int next = cur;
		int move = game[level];

		if (dir[next] > 0) {
			next = dir[next];
			move--;
		}

		while (move--) {
			if (next == 29) {
				next = 25;
			}
			else if (next == 32) {
				next = 25;
			}
			else if (next == 27) {
				next = 20;
			}
			else if (next == 21) {
				next = 21;
			}
			else next++;
		}

		if (check[next] && next != 21) continue;

		horse[i] = next;
		check[cur] = 0;
		check[next] = 1;

		dfs(level + 1, sum+MAP[next]);

		horse[i] = cur;
		check[cur] = 1;
		check[next] = 0;

	}

}

int main() {

	init();

	for (int i = 0; i < 10; i++) {
		cin >> game[i];
	}

	dfs(0, 0);

	cout << answer;


	return 0;
}