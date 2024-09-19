#include <iostream>

using namespace std;
int N;
int map[4][4];
int visited[4][4];
int dr[] = { 0,1 };
int dc[] = { 1,0 };
int flag = 0;

void DFS(int row, int col) {
	if (map[row][col] == -1 || flag) {
		flag = 1;
		return;
	}
	
	int how = map[row][col];
	for (int i = 0; i < 2; i++) {
		int nr = dr[i]* how + row;
		int nc = dc[i]* how + col;

		if (nr<0 || nc<0 || nr>=N || nc>=N)continue;
		if (visited[nr][nc]) continue;
		visited[nr][nc] = 1;
		DFS(nr, nc);
		visited[nr][nc] = 0;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int value;
			cin >> value;
			map[i][j] = value;
		}
	}
	visited[0][0] = 1;
	DFS(0, 0);
	if (flag) cout << "HaruHaru" << endl;
	else cout << "Hing" << endl;

	
	return 0;

}