#include <iostream>

using namespace std;

int Col, Row;
char arr[21][21];
int DAT[27] = { 0, };

int MAX = 0;
void dfs(int c, int r, int ans) {

	if (ans > MAX) {
		MAX = ans;
	}

	int dr[] = { 0, 0, -1, 1 };
	int dc[] = { 1,-1,0,0 };
	for (int i = 0; i < 4; i++) {
		int nr = dr[i] + r;
		int nc = dc[i] + c;

		if (nr<0 || nc<0 || nr>Row - 1 || nc>Col - 1)continue;
		if (DAT[arr[nc][nr] - 'A'])continue;
		DAT[arr[nc][nr] - 'A'] = 1;
		dfs(nc, nr, ans+1);
		
		DAT[arr[nc][nr] - 'A'] = 0;
	}

}


int main() {
	cin >> Col >> Row;
	for (int i = 0; i < Col; i++) {
		for (int j = 0; j < Row; j++) {
			cin >> arr[i][j];
		}
	}
	DAT[arr[0][0]-'A'] = 1;
	dfs(0,0,1);

	cout << MAX;
	return 0; 
}