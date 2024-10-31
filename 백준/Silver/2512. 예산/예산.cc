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

	ll MAX = -1e9;

	for (int i = 0; i < contry.size(); i++) {
		ll now = contry[i];
		
		
		if (under < contry[i]*(N-i)) {
			ll mok=under/(contry.size() - i);
			MAX=max(MAX, mok);
			cout << MAX << '\n';

			return 0;
		}
		under -= now;

		MAX = max(MAX, now);
	}

	cout << MAX << '\n';


	return 0;
}