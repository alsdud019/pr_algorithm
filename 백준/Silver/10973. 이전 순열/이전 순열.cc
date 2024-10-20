#include <iostream>
#include <algorithm>


using namespace std;

int N;
int arr[10001];

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int idx = -1;
	for (int i = N - 1; i >= 0; i--) {
		if (arr[i] < arr[i - 1]) {
			idx = i - 1;
			break;
		}
	}

	if (idx == -1) {
		cout << -1;
		return 0;
	}

	int now = arr[idx];

	int max = -1e9;
	int max_idx = -1;
	for (int i = idx + 1; i < N; i++) {
		if (now > arr[i] && max < arr[i]) {
			max = arr[i];
			max_idx = i;
		}
	}

	//교환
	arr[idx] = max;
	arr[max_idx] = now;

	sort(arr + idx + 1, arr + N, greater<>());

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}


	return 0;
}