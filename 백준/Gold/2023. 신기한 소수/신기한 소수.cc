#include <iostream>

using namespace std;

int N;

bool isPrime(int num) {
	for (int i = 2; i < num / 2; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void DFS(int number, int level) {

	if (level == N) {
		if (isPrime(number)) cout << number << endl;
		return;
	}

	for (int i = 1; i < 10; i++) {
		//짝수이면 넘어간다. 
		if (i % 2 == 0) continue;
		int new_num = number * 10 + i;
		//자릿수 추가 숫자가 소수이면 DFS 들어간다. 
		if (isPrime(new_num)) {
			DFS(new_num, level + 1);
		}
	}
}

int main() {

	cin >> N;
	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);
	return 0;
}