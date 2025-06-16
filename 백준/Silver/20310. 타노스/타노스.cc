#include <iostream>

using namespace std;

int main() {

	string str;
	cin >> str;

	int zero = 0;
	int one = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '0') zero++;
		else if (str[i] == '1') one++;
	}

	string answer;
	for (int i = 0; i < zero / 2; i++) {
		answer += '0';
	}
	for (int i = 0; i < one / 2; i++) {
		answer += '1';
	}

	cout << answer;
	return 0;
}