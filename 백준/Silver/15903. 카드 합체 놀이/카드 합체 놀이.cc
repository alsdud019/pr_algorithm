#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

int main() {

	int N, M;
	cin >> N >> M;

	vector<ll> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}

	for (int i = 0; i < M; i++) {
		sort(vec.begin(), vec.end());
		ll sum = vec[0] + vec[1];
		vec[0] = sum;
		vec[1] = sum;
	}

	ll total = 0;
	for (int i = 0; i < vec.size(); i++) {
		total += vec[i];
	}
	cout << total;

	


	return 0;
}