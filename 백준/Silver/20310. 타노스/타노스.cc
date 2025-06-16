#include <iostream>

using namespace std;

int check[501] = {0,};

int main() {

	string str;
	cin >> str;


	int zero = 0;
	int one = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '0') zero++;
		else if (str[i] == '1') one++;
	}

	int erase_zero = 0;
	for (int i = str.size() - 1; i >= 0; i--) {
		if (erase_zero == zero / 2) break;
		if (str[i] == '0') {
			check[i] = 1;
			erase_zero++;
		}
	}

	int erase_one = 0;
	for (int i = 0; i<= str.size() - 1; i++) {
		if (erase_one == one / 2) break;
		if (str[i] == '1') {
			check[i] = 1;
			erase_one++;
		}
	}

	string answer;
	for (int i = 0; i < str.size(); i++) {
		if (check[i] != 1) answer += str[i];
	}

	cout << answer;
	return 0;
}