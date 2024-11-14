#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, K;
	cin >> N >> K;

	vector<int> vec;
	vector<int> diff_vec;
	int answer = 0;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N - 1; i++) {
		int diff = abs(vec[i] - vec[i + 1]);
		diff_vec.push_back(diff);
	}

	sort(diff_vec.rbegin(), diff_vec.rend());

	for (int i = K - 1; i < diff_vec.size(); i++) {
		answer += diff_vec[i];
	}
	cout << answer;


	return 0;
}