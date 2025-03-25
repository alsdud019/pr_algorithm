#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, D;
int map[17][17];
int visited[17] = { 0, };
int answer = -1e9;

struct target {
	int y;
	int x;
	int cost;
};

bool cmp(target A, target B) {
	if (A.cost == B.cost) return A.x<B.x;
	return A.cost < B.cost;
}

void copy(int arr[17][17]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = map[i][j];
		}
	}
}

bool check(int arr[17][17]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}

void move(int arr[17][17]) {
	//한칸씩 아래로 이동 
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			arr[i + 1][j] = arr[i][j];
		}
	}

	for (int j = 0; j < M; j++) {
		arr[0][j] = 0;
	}

}

int attack() {

	int ans = 0;

	int arr[17][17];
	copy(arr);

	while (1) {
		//비어있는지 확인 
		if (check(arr)) break;

		vector<target> total;
		//공격 
		//궁수 조회 
		for (int k = 0; k < M; k++) {
			//공격할 궁수
			if (visited[k] == 1) {			
				//궁수 한명씩 공격가능한 적 vec에 저장 
				vector<target> vec;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						if (arr[i][j]==0 || abs(i - N) + abs(j - k) > D) continue;
						vec.push_back({ i,j,abs(i - N) + abs(j - k) });
					}
				}

				if (vec.empty()) continue;
				sort(vec.begin(), vec.end(), cmp);
				total.push_back({ vec[0].y, vec[0].x,vec[0].cost});
			}
		}

		for (auto t : total) {
			int now_y = t.y;
			int now_x = t.x;
			if (arr[now_y][now_x] == 1) {
				arr[now_y][now_x] = 0;
				ans++;
			}
		}

		//모든 공격을 끝내면 적군 이동
		move(arr);
	}
	
	return ans;
}

//조합 
void dfs(int level, int idx) {

	if (level == 3) {
		/*for (int i = 0; i < M; i++) {
			if (visited[i] == 1) {
				cout << i << " ";
			}
		}
		cout << endl;*/
		int re=attack();
		//cout << re << endl;
		answer = max(re, answer);
		return;
	}

	for (int i = idx; i < M; i++) {
		if (visited[i]) continue;

		visited[i] = 1;

		dfs(level + 1, i+1);

		visited[i] = 0;

	}
}

void solution() {

	dfs(0,0);

}

int main() {

	cin >> N >> M >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	solution();

	cout << answer;

	return 0;
}