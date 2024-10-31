#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<ll> contry;

int main() {

	ll N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll w;
		cin >> w;
		contry.push_back(w);
	}
	sort(contry.begin(), contry.end());

	ll under;
	cin >> under;

	for (int i = 0; i < N; i++) {
		int now = contry[i];

		if (under < contry[i] * (N - i)) {
			int result = under / (N - i);
			cout << result << '\n';
			return 0;
		}
		under -= now;
	}

	cout << contry[N - 1]<<'\n';


	return 0;
}