#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N, score, P;
	cin >> N >> score >> P;

	vector<int> vec;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	if (vec.size() < 1) {
		cout << 1;
		return 0;
	}

	if (vec.back() >= score && vec.size()>=P) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		int now = vec[i];
		if (now > score) {
			if (i == N - 1 || vec[i + 1] <= score) {
				cout << i + 2;
				return 0;
			}
		}
		else if (now <= score && i == 0) {
			cout << 1;
			return 0;
		}
	}




	return 0;
}