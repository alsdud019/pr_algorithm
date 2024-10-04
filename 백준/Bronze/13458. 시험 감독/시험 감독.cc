#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
ll N;
ll master, submaster;


vector<ll> room;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		ll num;
		cin >> num;
		room.push_back(num);
	}
	cin >> master >> submaster;
	ll count = 0;
	for (int i = 0; i < room.size(); i++) {
		room[i] -= master;
		count++;
		if (room[i] > 0) {
			count+=room[i] / submaster;
			if (room[i] % submaster != 0) count++;
		}
	}
	cout << count;

	return 0;
}