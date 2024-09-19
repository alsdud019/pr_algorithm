#include <iostream>


using namespace std;

int N, M, K;
int map[101][101];
int visited[101][101];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int trash = 1;
int MAX = -9999;

void DFS(int row, int col) {
	for (int i = 0; i < 4; i++) {
		int nr = dr[i] + row;
		int nc = dc[i] + col;

		if (nr<0 || nc<0 || nr>N-1 || nc>M -1) continue;
		if (visited[nr][nc]) continue;
		if (map[nr][nc] == 1) {
			visited[nr][nc] = 1;
			trash++;
			DFS(nr, nc);
		}
		

	}
}

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int col, row;
		cin >> row >> col ;
		map[row-1][col-1] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 || visited[i][j]==1) continue;
			visited[i][j] = 1;
			DFS(i, j);
			if (MAX < trash) {
				MAX = trash;
			}
			trash = 1;

		}
	}
	cout << MAX << endl;

	return 0;
}