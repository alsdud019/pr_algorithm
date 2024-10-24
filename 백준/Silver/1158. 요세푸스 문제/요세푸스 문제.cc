#include <iostream>
#include <queue>
using namespace std;

int N, K;
int DAT[50001];

int main() {
	cin >> N >> K;
	queue<int> q;
	int idx = 0;
	int i = 0;
	while (q.size()<N) {

		for (int i = 1; i <= N; i++) {
			if (DAT[i] == 1) continue;
			idx++;
			if (idx == K) {
				q.push(i);
				idx = 0;
				DAT[i] = 1;
				/*break;*/
			}
		}
	}
	cout << "<";
	for (int i = 0; i < N-1; i++) {
		int now = q.front(); q.pop();
		cout << now << ", ";
	}
	cout << q.front();
	cout << ">";


	return 0;
}