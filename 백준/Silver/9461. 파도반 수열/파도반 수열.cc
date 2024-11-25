#include <iostream>
#include <string.h>

using namespace std;

long long dp[101];

void init() {

	memset(dp, 0, sizeof(dp));

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
}


int main() {

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		init();

		if (N > 5) {
			for (int i = 6; i <= N; i++) {
				dp[i] = dp[i - 5] + dp[i - 1];
			}
		}

		cout << dp[N]<<'\n';
	}

	return 0;
}