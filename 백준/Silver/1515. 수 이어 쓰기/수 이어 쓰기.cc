#include <iostream>
#include <string>

using namespace std;

int main() {

	string N;
	cin >> N;

	int now = 1;
	int idx = 0;

	while (idx <= N.length() - 1) {

		string now_str = to_string(now);

		for (int i = 0; i < now_str.length(); i++) {
			if (N[idx] == now_str[i]) {
				idx++;
			}

			if (idx > N.length() - 1) {
				cout << now;
				break;
			}

		}

		now++;
	}

	return 0;
}