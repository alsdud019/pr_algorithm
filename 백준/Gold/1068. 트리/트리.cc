#include <iostream>
#include <vector>

using namespace std;

int N, D;
vector<int> vec[51];
int cnt = 0;

void dfs(int now) {

	if (vec[now].size() == 0|| vec[now].size()==1 && vec[now][0]==D) {
		cnt++;
		return;
	}

	//cout << now << " ";
	for (int i = 0; i < vec[now].size(); i++) {
		int next = vec[now][i];
		if (next == D) continue;
		dfs(next);

	}


}

int main() {

	cin >> N;

	int root = -1;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == -1) root = i;
		else vec[num].push_back(i);
	}
	cin >> D;

	if (root == D) {
		cout << 0;
		return 0;
	}
	dfs(root);
	cout << cnt;


	return 0;
}