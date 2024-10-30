#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;

		vector<int> A;
		vector<int> B;
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			A.push_back(num);
		}
		for (int i = 0; i < M; i++) {
			int num;
			cin >> num;
			B.push_back(num);
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		
		int answer = 0;
		for (int i = 0; i < A.size(); i++) {
			int left = 0;
			int right = B.size() - 1;

			while (left <= right) {
				int mid = (left + right) / 2;

				if (A[i] <= B[mid]) {
					right = mid - 1;
				}
				else{
					left = mid + 1;
				}
			}
			if (left > 0) {
				answer += left;
			}
		}

		cout << answer << '\n';
		
	}
	return 0;
}