#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;
	int answer = 0;

	// 5의 배수인지 확인 
	if (N % 5 == 0) {
		cout << N / 5;
		return 0;
	}

	//2의 배수 일때까지 5를 뺀다. 
	while (true) {
		if (N < 0) {
			cout << -1;
			return 0;
		}

		if (N%5==0) {
			answer += N / 5;
			break;
		}
		N -= 2;
		answer++;
	}
	
	//N이 2의 배수가 되면
	cout << answer;

	return 0;
}