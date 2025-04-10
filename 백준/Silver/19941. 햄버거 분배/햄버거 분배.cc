#include <iostream>
#include <string>

using namespace std;

int main() {

	int N, K;

	cin >> N >> K;

	string seq;
	cin >> seq;

	int answer = 0;

	for (int i = 0; i < N; i++) {
		if (seq[i] == 'P') {
			//왼쪽 거리만큼 확인 
			bool left_flag = false;
			for (int j = K; j >= 1; j--) {
				if (i - j < 0) continue;
				if (seq[i-j] == 'H') {
					answer++;
					seq.replace(i - j, 1, "N");
					left_flag = true;
					break;
				}
			}
			if (left_flag) continue;

			for (int j = 1; j <= K; j++) {
				if (i + j > N - 1)continue;
				if (seq[i + j] == 'H') {
					answer++;
					seq.replace(i + j, 1, "N");
					break;
				}
			}
		}
	}

	cout << answer;
	return 0;
}