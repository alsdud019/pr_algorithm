#include <iostream>
#include <vector>


using namespace std;

int main() {

	int N;
	cin >> N;

	int arr[1001];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	vector<int> dp(N, 1);

	int answer = -1e9;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		answer = max(answer, dp[i]);
	}

	cout << answer;

	return 0;
}