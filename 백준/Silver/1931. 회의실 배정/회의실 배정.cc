#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N; 
	cin >> N;

	vector<pair<int, int>> vec(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i].second;
		cin >> vec[i].first;
	}

	sort(vec.begin(), vec.end());

	int end = -1;
	int count = 0;

	for (int i = 0; i < vec.size(); i++) {
		if (end <= vec[i].second) {
			count++;
			end = vec[i].first;
		}
	}

	cout << count;


	return 0;
}