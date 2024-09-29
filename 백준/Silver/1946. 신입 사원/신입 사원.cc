#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	int T; 
	cin >> T;
	while (T--) {
		int N;
		cin >> N;

		vector<pair<int, int>> vec(N);

		for (int i = 0; i < N; i++) {
			cin >> vec[i].first >> vec[i].second;
		}

		sort(vec.begin(), vec.end());
		int prsentation = vec[0].second;
		int count = 1;
		for (int i = 1; i < vec.size(); i++) {
			if (prsentation > vec[i].second) {
				prsentation = vec[i].second;
				count++;
			}
		}
		cout << count << '\n';
	}
	
	return 0;
}