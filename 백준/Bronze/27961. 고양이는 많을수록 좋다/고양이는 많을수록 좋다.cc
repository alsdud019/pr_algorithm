#include <iostream>

using namespace std;

int main() {

	long long N;
	cin >> N;

	long long now = 0;
	long long  cnt = 0;

	while (true) {
		if (now >= N) {
			break;
		}
		if (now == 0) {
			now++;
		}
		else {
			now += now;
		}
		cnt++;

	}
	cout << cnt;

	return 0;
}