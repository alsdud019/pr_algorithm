#include <iostream>
#include <cmath>

using namespace std;
int T;
using ll = unsigned long long;

void cross_bridge(ll n) {
	ll left = 1;
	ll right = n;
	ll answer = -1e9;

	while (left <= right) {
		ll mid = (left + right) / 2;

		if (mid * (mid + 1) <= 2 * n) {
			left = mid + 1;
			answer = mid;
		}
		else right = mid - 1;
	}
	cout << answer << '\n';

}

int main() {
	cin >> T;

	while (T--) {
		ll N;
		cin >> N;

		cross_bridge(N);

	}

	return 0;
}