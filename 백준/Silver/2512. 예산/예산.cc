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

	ll left = 0;
	ll right = contry[N - 1];

	ll answer = 0;


	while(left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;

		for (int i = 0; i < contry.size(); i++) {
			sum += min(contry[i], mid);
		}
		if (sum <= under) {
			left = mid + 1;
			answer = mid;
		}
		else {
			right = mid - 1;
		}
	}

	cout << answer << '\n';


	return 0;
}