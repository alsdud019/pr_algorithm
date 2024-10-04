#include <iostream>

using namespace std;
int N;
int member[21][21];
int visited[21] = { 0, };

int MIN = 1e9;


void dfs(int cnt, int pos) {
	if (cnt == N / 2) {
		int start = 0;
		int link = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j)continue;
				if (visited[i] && visited[j]) start += member[i][j];
				else if (!visited[j] && !visited[i]) link += member[i][j];
			}
		}
		int result=abs(link - start);
		if (result < MIN) MIN = result;

		return;
	}

	for (int i = pos; i < N; i++) {
		if (visited[i] ) continue;
		visited[i] = 1;
		dfs(cnt + 1, i);
		visited[i] = 0;
	}
}


int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> member[i][j];
		}
	}


	dfs(0,0);

	cout << MIN;

	return 0;
}