#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

ll N;

int digits(int num) {
	num=num / 10;
	int cnt = 1;
	while (num > 0) {
		num /= 10;
		cnt++;
	}

	return cnt;
}

int main() {
	cin >> N;
	ll answer = 0;

	int jari = digits(N);

	//이전 자리수까지 더하기 
	for (int i = 0; i < jari-1; i++) {
		answer += pow(10, i)*9*(i+1);

	}

	//현재 자리수 일때
	//숫자 - 자리수 첫숫자 +1 * 자릿수 
	answer+=(N+1 - pow(10, jari - 1) )* jari;

	
	cout << answer << endl;


	return 0;
}