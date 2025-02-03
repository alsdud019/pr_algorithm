#include <iostream>

using namespace std;
int N;
int used[16];
int answer = 0;

void dfs(int level) {
	if (level == N) {
		answer++;
		return ;
	}

	for (int i = 1; i <= N; i++) {

		int next = i;

		bool toggle = true;
		for (int j = 0; j < level; j++) {
			if (used[j] == next || abs(used[j] - next) == level - j) {
				toggle = false;
				break;
			}
		}
		if (toggle) {
			used[level] = next;
			dfs(level + 1);
		}
		
	}


}

int main() {

	cin >> N;

	dfs(0);
	cout << answer;


	return 0;
}