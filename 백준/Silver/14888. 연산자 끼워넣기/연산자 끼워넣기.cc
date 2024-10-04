#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
int N;

vector<ll> num_vec;
int op[5];
ll MAX = -1e9;
ll MIN = 1e9;

void dfs(int idx, ll sum) {

	if (idx == N - 1) {
		if (MIN > sum) MIN = sum;
		if (MAX < sum) MAX = sum;
		return;
	}
	if (idx > N - 1) return;
	for (int i = 0; i < 4; i++) {
		if (op[i] == 0) continue;
		op[i]--;
		if (i == 0) dfs(idx + 1, sum + num_vec[idx + 1]);
		else if (i == 1) dfs(idx + 1, sum - num_vec[idx + 1]);
		else if (i == 2) dfs(idx + 1, sum * num_vec[idx + 1]);
		else dfs(idx + 1, sum / num_vec[idx + 1]);
		op[i]++;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		num_vec.push_back(num);
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	dfs(0, num_vec[0]);

	cout << MAX << '\n';
	cout<<MIN;
	return 0;
}