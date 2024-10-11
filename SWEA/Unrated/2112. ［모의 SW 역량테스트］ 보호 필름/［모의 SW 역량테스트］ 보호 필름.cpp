#include <iostream>
#include <cstring>

using namespace std;

int T;
int D, W, K;
int MAP[21][21];
int visited[21];

int C_MAP[21][21];
int MIN;

void init() {
	memset(MAP, 0, sizeof(MAP));
	memset(visited, 0, sizeof(visited));
	memset(C_MAP, 0, sizeof(C_MAP));
	MIN = 1e9;

	cin >> D >> W >> K;
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			cin >> MAP[i][j];
			C_MAP[i][j] = MAP[i][j];
		}
	}

}
void make_map(int d, int what, int toggle) {
	if (toggle) {
		for (int i = 0; i < W; i++) {
			C_MAP[d][i] = what;
		}
	}
	else {
		for (int i = 0; i < W; i++) {
			C_MAP[d][i] = MAP[d][i];
		}
	}
	
}

bool check(int C_MAP[][21]) {
	bool t_flag = true;
	for (int i = 0; i < W; i++) {
		//세로줄 시작 
		bool flag = false;
		for (int j = 0; j < D - K + 1; j++) {
			int cnt = 1;
			int first = C_MAP[j][i];
			for (int k = 1; k < K; k++) {
				if (first == C_MAP[j + k][i]) {
					cnt++;
				}
			}
			if (cnt == K) {
				flag = true;
				break;
			}
			//if (C_MAP[j][i] == C_MAP[j + 1][i] && C_MAP[j + 1][i] == C_MAP[j + 2][i]){
			//	flag = true;
			//	break;
			//}
		}
		if (flag == false) {
			t_flag = false;
			break;
		}
	}
	return t_flag;
}

void DFS(int idx, int cnt) {

	//종료조건
	if (check(C_MAP)) {
		if (MIN > cnt) MIN = cnt;
		return;
	}

	if (cnt > K || MIN < cnt) return;

	for (int i = idx; i < D; i++) {
		if (visited[i] == 1) continue;
		visited[i] = 1;
		//A를 넣을지 B를 넣을지 
		for (int j = 0; j < 2; j++) {
			make_map(i, j, true);
			DFS(i, cnt + 1);
			make_map(i, j, false);

		}
		visited[i] = 0;
	}
}

void Solution() {
	if (K == 1) {
		MIN = 0;
		return;
	}
	DFS(0,0);
	//cout<<check(MAP)<<endl;
}

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		init();
		Solution();
		cout << '#' << i << " " << MIN<<'\n';
	}

	return 0;
}