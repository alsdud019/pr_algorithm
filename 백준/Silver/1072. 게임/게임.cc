#include <iostream>

using namespace std;

long long X, Y;
long long MAX = 1000000000;

int main() {

	cin >> X >> Y;

	int Z = Y * 100 / X;

	if (Z >= 99) {
		cout << -1;
		return 0;
	}

	int left = 0; int right = MAX;


	while (left <= right) {
		long long x = X;
		long long y = Y;

		int mid = (left + right) / 2;
		x += mid;
		y += mid;
		int now_win = y * 100 / x;

		if (Z < now_win) right = mid - 1;
		else left = mid + 1;
	}

	cout << left;


	return 0;
}