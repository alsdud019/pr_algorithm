#include <iostream>
#include <vector>

using namespace std;

int N;
long long k;
int DAT[21];
long long fact[21];

int main() {

	cin >> N;
	int question;
	cin >> question;

	fact[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = fact[i - 1] * i;
	}

	if (question == 1) {
		cin >> k;
		vector<int> ans(N);
		for (int level = 0; level < N; level++) {
			for (int i = 1; i <= N; i++) {
				if (DAT[i])continue;
				if (k > fact[N - level-1]) {
					k -= fact[N - level-1];
				}

				else if (k <= fact[N - level-1]) {
					ans[level] = i;
					DAT[i] = 1;
					break;
				}

			}
		}
		for (int i = 0; i < N; i++) {
			cout << ans[i] << " ";
		}

	}
	
	else if (question ==2){
		vector<int>input(N);

		for (int i = 0; i < N; i++) {
			cin >> input[i];
		}

		long long sum = 0;
		for (int level = 1; level < N; level++) {
			for (int i = 1; i <= N; i++) {
				if (DAT[i]) continue;
				if (i == input[level - 1]) {
					DAT[i] = 1;
					break;
				}
				sum+=fact[N - level];
				

			}
		}
		
		cout << sum + 1;

	}

	return 0;
}