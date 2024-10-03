#include <iostream>

using namespace std;

char arr[27][2];

void preOrder(char now) {
	if (now == '.') return;
	cout << now;
	preOrder(arr[now - 'A'][0]);
	preOrder(arr[now - 'A'][1]);
}

void inOrder(char now) {
	if (now == '.') return;
	inOrder(arr[now - 'A'][0]);
	cout << now;
	inOrder(arr[now - 'A'][1]);
}

void postOrder(char now) {
	if (now == '.') return;
	postOrder(arr[now - 'A'][0]);
	postOrder(arr[now - 'A'][1]);
	cout << now;
}

int main() {

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char mid, left, right;
		cin >> mid >> left >> right;
		arr[mid - 'A'][0] = left;
		arr[mid - 'A'][1] = right;
	}

	preOrder('A');
	cout << '\n';
	inOrder('A');
	cout << '\n';
	postOrder('A');
	cout << '\n';

	return 0;
}
