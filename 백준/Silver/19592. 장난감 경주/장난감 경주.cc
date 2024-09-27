#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		double N, X, Y;
		cin >> N >> X >> Y;
		vector<double> vec;

		int me_speed;
		for (int j = 1; j <= N; j++) {
			double s;
			cin >> s;
			if (j == N) {
				me_speed = s;
				break;
			}
			double time = X / s;

			vec.push_back(time);

		}

		sort(vec.begin(), vec.end());

		if (vec[0] > X / me_speed) cout << 0 << endl;
		else if ((X - Y) / me_speed + 1 >= vec[0]) cout << -1 << endl;
		else {
			int left = 0; int right = Y;
			while (left <= right) {
				int mid = (left + right) / 2;
				if ((X - mid) / me_speed + 1 >= vec[0]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			cout << left << endl;
		}
	}

	return 0;
}