#include <iostream>
#include <cstring>

using namespace std;
int N;
int score[51][10];
int check[10];
int order[10];
int answer = -1e9;

void calcum() {
	int last_num = 1;
	int yard[5] = { 0, };
	int total = 0;

	//이닝 수 만큼 진행
	for (int i = 1; i <= N; i++) {
		int out = 0;
		memset(yard, 0, sizeof(yard));
		while (out!=3) {
				int now_score = score[i][order[last_num]];

				//아웃일 때 
				if (now_score == 0) {
					out++;
				}
				else if (now_score == 1) {
					for (int i = 3; i >= 1; i--) {
						if (yard[i]) {
							if (i + 1 >= 4) {
								yard[4]++;
								yard[i] = 0;
							}
							else {
								yard[i + 1]=1;
								yard[i] = 0;
							}
						}
					}
					yard[1] = 1;

				}
				else if (now_score == 2) {
					for (int i = 3; i >= 1; i--) {
						if (yard[i]) {
							if (i + 2 >= 4) {
								yard[4]++;
								yard[i] = 0;
							}
							else {
								yard[i + 2]=1;
								yard[i] = 0;
							}
						}
					}
					yard[2] = 1;

				}
				else if (now_score == 3) {
					for (int i = 3; i >= 1; i--) {
						if (yard[i]) {
							yard[4]++;
							yard[i] = 0;							
						}
					}
					yard[3] = 1;

				}
				else if (now_score == 4) {
					for (int i = 3; i >= 1; i--) {
						if (yard[i]) {
							yard[4]++;
							yard[i] = 0;
						}
					}
					yard[4]++;
				}
				total += yard[4];
				yard[4] = 0;

				last_num++;
				if (last_num >= 10) last_num = 1;
		}
		
	}
	answer = max(answer, total);
}

void dfs(int level) {

	if (level == 10) {
		calcum();
		return;
	}

	if (level == 4) level += 1;

	for (int i = 1; i <= 9; i++) {
		if (check[i]) continue;

		check[i] = 1;
		order[level] = i;

		dfs(level + 1);

		check[i] = 0;
		order[level] = 0;
	}
}

int main() {

	cin >> N;
	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> score[i][j];
		}
	}

	order[4] = 1;
	check[1] = 1;

	dfs(1);

	cout << answer;

	return 0;
}