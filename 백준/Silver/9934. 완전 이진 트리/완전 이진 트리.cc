#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
vector<int> input;
vector<int> arr[1024];

void recur(int st, int end, int depth) {

	if (st>end) return;
	int mid = (st + end) / 2;

	arr[depth].push_back(input[mid]);
	recur(st, mid - 1, depth + 1);
	recur(mid + 1, end, depth + 1);
}

int main() {

	int K;
	cin >> K;
	for (int i = 0; i < pow(2, K) - 1; i++) {
		int num;
		cin >> num;
		input.push_back(num);
	}

	recur(0, input.size() - 1, 1);

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}