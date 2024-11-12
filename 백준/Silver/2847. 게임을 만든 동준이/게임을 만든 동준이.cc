#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> vec;
	int answer = 0;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	for (int i = N - 1; i > 0; i--) {
		int now = vec[i];
		if (now <= vec[i - 1]) {
			answer += (vec[i - 1] - now) + 1;
			vec[i - 1] = now - 1;
		}
	}

	cout << answer;


	return 0;
}