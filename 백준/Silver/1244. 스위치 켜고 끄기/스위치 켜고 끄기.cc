#include <iostream>

using namespace std;

int N, M;
int arr[101];

void change(int num) {
	if (arr[num] == 0) arr[num] = 1;
	else arr[num] = 0;
}

void print() {
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
		if (i % 20 == 0) cout << '\n';
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int gender, num;
		cin >> gender >> num;

		//남자이면
		if (gender == 1) {
			int gop = 1;
			int now=num;
			while (now<=N) {
				change(now);
				gop += 1;
				now = num * gop;
			}
		}
		//여자이면 
		else if (gender == 2) {
			int gap = 1;
			int left = num - gap;
			int right = num + gap;

			while (left >= 1 && right <= N) {
				if (arr[left] == arr[right]) {
					change(left);
					change(right);
					gap += 1;
					left = num - gap;
					right = num + gap;
				}
				else break;
			}
			change(num);
		}
	}

	print();



	return 0;
}