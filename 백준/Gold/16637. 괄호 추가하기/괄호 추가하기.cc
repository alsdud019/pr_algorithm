#include <iostream>

using namespace std;
int N;
string sentence;

int answer = -1e9;

int calcul(int a, int b, char oper) {
	if (oper == '+') return a + b;
	else if (oper == '-') return a - b;
	else if (oper == '*') return a * b;

}

void dfs(int level, int result) {
	//종료조건
	if (level >= N) {
		answer = max(answer, result);
		return;
	}

	char op;
	if (level == 0) {
		op = '+';
	}
	else {
		op = sentence[level - 1];
	}

	//괄호를 사용할 때
	if (level + 2 < N) {
		int a = sentence[level] - '0';
		int b = sentence[level + 2] - '0';
		int oper = sentence[level + 1];
		int re = calcul(a, b, oper);

		dfs(level+4,calcul(result, re, op));

	}

	//괄호를 사용하지 않았을때
	dfs(level + 2, calcul(result, sentence[level]-'0', op));

}


int main() {

	cin >> N;
	cin >> sentence;

	dfs(0,0);
	
	cout << answer;

	return 0;
}