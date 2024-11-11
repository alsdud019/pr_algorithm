#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		string answer = "";
		for (int i = 0; i < N; i++) {
			char c;
			cin >> c;
			
			//비어있다면
			if (answer.size() < 1) {
				answer += c;
			}
			
			else {
				//문자가 빠른문자라면 
				if (c<=answer[0]) {
					answer = c + answer;
				}
				else {
					answer = answer + c;
				}
			}
		}
		cout << answer << '\n';
	}

	return 0;
}