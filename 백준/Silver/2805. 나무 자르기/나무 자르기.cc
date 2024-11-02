#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {

	ll N, M;
	cin >> N >> M;

	vector<ll> trees;

	for (int i = 0; i < N; i++) {
		ll num;
		cin >> num;
		trees.push_back(num);
	}

	sort(trees.begin(), trees.end());

	ll left = 0;
	ll right = trees[N-1];
	ll MAX = -1e9;

	while (left <= right) {
		ll mid = (left + right) / (ll)2;

		ll remain = 0;
		for (int i = 0; i < N; i++) {
			if (trees[i] >= mid) {
				remain += (trees[i] - mid);
			}
		}

		if (remain >= M) {
			left = mid + 1;
			MAX = max(MAX, mid);
		}
		else {
			right = mid - 1;
		}
	}

	cout << MAX << '\n';


	return 0;
}