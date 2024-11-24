#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;

	int arr[1001];
	int dp[1001] = { 0, };

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

	

	//dp[0] = arr[0];
	int answer = -1e9;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[j] + arr[i], dp[i]);
			}
		}
		answer = max(answer, dp[i]);
	}

	cout << answer;


	return 0;
}