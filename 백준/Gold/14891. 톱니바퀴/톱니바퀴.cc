#include <iostream>
#include <cmath>

using namespace std;

string wheel[5];
int K;
int howRotate[4];

void rotate(int num, int d) {
	//반시계방향 
	if (d == -1) {
		char tmp = wheel[num][0];
		for (int i = 0; i < 7; i++) {
			wheel[num][i] = wheel[num][i + 1];
		}
		wheel[num][7] = tmp;
	}
	//시계방향
	else if (d == 1) {
		char tmp = wheel[num][7];
		for (int i = 7; i > 0; i--) {
			wheel[num][i] = wheel[num][i - 1];
		}
		wheel[num][0] = tmp;
	}
}

void leftCheck(int num, int d) {
	if (num <= 0) return;
	if (wheel[num][6] != wheel[num - 1][2]) {
		howRotate[num - 1] = d * -1;
		leftCheck(num - 1, howRotate[num - 1]);
	}
}

void rightCheck(int num, int d) {
	if (num >= 3) return;
	if (wheel[num][2] != wheel[num + 1][6]) {
		howRotate[num + 1] = d * -1;
		rightCheck(num + 1, howRotate[num + 1]);
	}
}

void Play(int num, int d) {

	howRotate[num] = d;
	leftCheck(num,d);
	rightCheck(num, d);

	for (int i = 0; i < 4; i++) {
		rotate(i, howRotate[i]);
	}

	for (int i = 0; i < 4; i++) howRotate[i] = 0;
	
}


int main() {
	
	for (int i = 0; i < 4; i++) {
		cin >> wheel[i];
	}
	cin >> K;

	for (int i = 0; i < K; i++) {
		int num, d;
		cin >> num >> d;
		Play(num-1, d);
	}
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0]=='1') sum += pow(2, i);
		
	}
	cout << sum;

	return  0;
}