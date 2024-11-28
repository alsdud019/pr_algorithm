#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N;
	cin >> N;

	int arr[1001] = {0,};

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	vector<int> dp(N, 1);
	


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	vector<int> r_dp(N, 1);

	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j > i; j--) {
			if (arr[j] < arr[i]) {
				r_dp[i] = max(r_dp[i], r_dp[j] + 1);
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer = max(answer, dp[i] + r_dp[i]);
	}

	cout << answer-1;



	return 0;
}