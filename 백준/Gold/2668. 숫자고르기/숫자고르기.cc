#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int arr[101];
int visited[101];
vector<int> ans;

void dfs(int now, int first) {

	if (visited[now]) {
		if (now == first) {
			ans.push_back(now);
		}
		return;
	}
	visited[now] = 1;
	dfs(arr[now], first);

}


int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <=N ; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i, i);
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';

	return 0;
}