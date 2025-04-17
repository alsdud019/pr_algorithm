#include <iostream>

using namespace std;

int N;
string input, goal;

void change(string &str, int idx) {
	for (int i = idx - 1; i <= idx + 1; i++) {
		if (i<0 || i>str.size() - 1) continue;
		str[i] = (str[i] == '0') ? '1' : '0';
	}
}

int check(bool flag) {

	string temp = input;
	int answer = 0;


	if (flag) { //첫번째 스위치 누르기 
		temp[0] = temp[0] == '0' ? '1' : '0';
		temp[1] = temp[1] == '0' ? '1' : '0';
		answer++;
	}

	for (int i = 1; i < N; i++) {
		if (temp[i - 1] != goal[i - 1]) {
			change(temp, i);
			answer++;
		}
	}
	if (goal == temp) return answer;
	else return 1e9;

}

int main() {


	cin >> N;

	cin >> input >> goal;

	
	//두 결과값 비교, 작은값 선택 
	int answer = min(check(0), check(1));

	//만약 작은값이 무한대라면 -1 출력 
	if (answer == 1e9) cout << -1;
	else cout << answer;


	return 0;
}