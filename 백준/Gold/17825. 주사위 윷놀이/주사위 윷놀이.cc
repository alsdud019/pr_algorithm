#include <iostream>

using namespace std;
int map[34];
int turn[34];
int horse[4] = {0,};
int check[34];

int dices[11];

int answer = -1e9;


void init() {

	for (int i = 1; i < 21; i++) {
		map[i] = 2 * i;
	}
	map[22] = 13; map[23] = 16; map[24] = 19;
	map[25] = 25; map[26] = 30; map[27] = 35;
	map[29] = 22; map[30] = 24;
	map[31] = 28; map[32] = 27; map[33] = 26;

	turn[5] = 22; turn[10] = 29; turn[15] = 31;


}

void dfs(int level, int sum) {
	if (level == 10) {
		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int move=dices[level];
		int current = horse[i];
		int next = current; //다음 이동: 현재 위치에서 시작

		//갈림길에서 방향 바꿔주기 
		if (turn[current] > 0) {
			next = turn[current];
			move--;
		}
		
		while (move--) {
			if (next == 30) {
				next = 25;
			}
			else if (next == 33) {
				next = 25;
			}
			else if (next == 27) {
				next = 20;
			}
			else if (next == 21) {
				next = 21;
			}
			else next += 1;
		}
		
		if (next != 21 && check[next]) continue; //다음 옮길 장소가 도착장소가 아닌데 다른 말이 존재한다면 

		check[current] = 0; //말이 있는 곳 해제하기
		check[next] = 1; //말이 이동할 곳으로 체크하기 
		horse[i] = next;

		dfs(level + 1, sum + map[next]);

		check[current] = 1;
		check[next] = 0;
		horse[i] = current;


	}
}

int main() {

	init();

	for (int i = 0; i < 10; i++) {
		cin >> dices[i];
	}

	dfs(0,0);

	cout << answer;


	return 0;
}