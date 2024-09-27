#include <iostream>
#include <unordered_map>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
unordered_map<int, int> m;
int N, M, answer;


int main() {
	fastio;
	while (1) {

		cin >> N >> M;
		if (N==0 && M==0) break;

		answer = 0;
		m.clear();

		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			m[num] = 1;
		}
		for (int i = 0; i < M; i++) {
			int num;
			cin >> num;
			if (m[num]) answer++;
		}

		cout << answer << '\n';

	}
	
	return 0;
}