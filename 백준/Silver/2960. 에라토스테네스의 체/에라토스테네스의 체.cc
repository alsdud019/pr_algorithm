#include <iostream>

using namespace std;

int era[10001] = { 0 ,};
int N, K;

int main() {

	cin >> N >> K;
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		int idx = 1;
		while (1) {
			int now = i * idx;
			if (now > N) break;
			if (era[now] == 0) {
				era[now] = 1;
				cnt++;
			}
			if (cnt == K) {
				cout << now << '\n';
				return 0;
			}
			idx++;
		}
		
	}

	return 0;
}