#include <iostream>

using namespace std;
double X, Y;


int main() {
	cin >> X >> Y;
	int win = Y *100 / X;

	if (X == Y || win>=99) {
		cout << -1;
		return 0;
	}

	double x = X;
	double y = Y;

	while (1) {
		x += 1;
		y += 1;
		int now_win = y / x * 100;

		if (now_win > win) {
			break;
		}
	}

	long long answer = y - Y;
	cout << answer;
	
	return 0;
}