#include <iostream>

using namespace std;

long long N;

int main() {

	cin >> N;

	long long idx = 0;

	long long now = 1;
	while (1) {
		if (N <= now) {
			break;
		}
		idx += 1;
		now += (6 * idx);
	}

	cout << idx + 1;
	
	return 0;
}