#include <iostream>

using namespace std;

int N;
int T[16];
int P[16];
int MAX = 0;

void dfs(int day, int sum) {
	if (day > N + 1) {
		return;
	}

	MAX = max(sum, MAX);
	//cout << sum << endl;

	for (int i = day; i <= N; i++) {
		dfs(T[i] + i, sum + P[i]);
	}


}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	dfs(1, 0);

	cout << MAX;

	return 0;
}