#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N;
	cin >> N;

	int arr[201] = {0,};

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	vector<int> dp(N, 1);

	int answer = -1e9;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		answer = max(dp[i], answer);
	}

	cout << N-answer;

	return 0;
}