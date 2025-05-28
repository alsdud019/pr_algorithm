#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;

	int kbs1_idx, kbs2_idx;

	for (int i = 0; i < N; i++) {
		string channel[101];
		cin >> channel[i];

		if (channel[i] == "KBS1") kbs1_idx = i;
		if (channel[i] == "KBS2") kbs2_idx = i;

	}

	for (int i = 0; i < kbs1_idx; i++) {
		cout << "1";
	}

	for (int i = kbs1_idx - 1; i >= 0; i--) {
		cout << "4";
	}

	if (kbs2_idx < kbs1_idx) kbs2_idx += 1;

	for (int i = 0; i < kbs2_idx; i++) {
		cout << "1";
	}

	for (int i = kbs2_idx - 1; i >= 1; i--) {
		cout << "4";
	}


	return 0;
}