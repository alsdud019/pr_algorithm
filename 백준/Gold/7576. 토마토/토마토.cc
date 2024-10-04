#include <iostream>
#include <queue>

using namespace std;

int ROW,COL;

int box[1001][1001];
int dr[] = { 0,0,-1,1 };
int dc[] = { -1,1,0,0 };
int day = 0;
int result = 0;

struct Node {
	int row;
	int col;
};

queue<Node> q;


void bfs() {
	
	


	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nextRow = dr[i] + now.row;
			int nextCol = dc[i] + now.col;

			if (nextRow<0 || nextCol<0 || nextCol>COL - 1 || nextRow>ROW - 1)continue;
			if (box[nextCol][nextRow] != 0)continue;

			q.push({ nextRow, nextCol });
			box[nextCol][nextRow] =box[now.col][now.row]+1;
		}


	}


}

int main() {
	cin >> ROW >> COL;

	int srow=-1;
	int scol=-1;
	for (int i = 0; i < COL; i++) {
		for (int j = 0; j < ROW; j++) {
			cin >> box[i][j];
			if (box[i][j]==1) q.push({ j,i });

		}
	}

	bfs();

	for (int i = 0; i < COL; i++) {
		for (int j = 0; j < ROW; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (result < box[i][j]) result = box[i][j];
		}
	}

	cout << result-1;


	

	return 0;
}