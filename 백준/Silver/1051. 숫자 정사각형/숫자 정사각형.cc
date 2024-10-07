#include <iostream>

using namespace std;

int Col, Row;
int MAP[51][51];
int MIN;
int MAX = -99;

void Find(int k) {
	for (int i = 0; i < Col; i++) {
		for (int j = 0; j < Row; j++) {
			if (i + k > Col - 1 || j + k > Row - 1) continue;
			int first = MAP[i][j];
			int second = MAP[i][j + k];
			int third = MAP[i + k][j];
			int forth = MAP[i + k][j + k];
			if (first == second && second == third && third == forth) {
				if (k + 1 > MAX) {
					MAX = k + 1;
					break;
				}
			}

		}
	}
}

int main() {

	cin >> Col >> Row;

	for (int i = 0; i < Col; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < Row; j++) {
			MAP[i][j] = input[j] - '0';
		}
	}
	MIN = min(Col, Row);


	for (int k = 0; k < MIN; k++) {
		Find(k);
	}
	
	cout << MAX*MAX;
	return 0;
}