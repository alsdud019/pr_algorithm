#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int Col, Row;
char MAP[51][51];
int visited[51][51] = {0,};
int path[51][51] = {0,};

struct Node {
	int row;
	int col;
};

int bfs(int stRow, int stCol) {

	queue<Node>q;
	q.push({ stRow,stCol });
	visited[stCol][stRow] = 1;

	int MAX = -1;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		int dr[] = { 0,0,-1,1 };
		int dc[] = { 1,-1,0,0};

		for (int i = 0; i < 4; i++) {
			int nextRow = now.row + dr[i];
			int nextCol = now.col + dc[i];

			if (nextRow<0 || nextCol<0 || nextRow>Row - 1 || nextCol>Col - 1) continue;
			if (visited[nextCol][nextRow] || MAP[nextCol][nextRow] == 'W') continue;

			path[nextCol][nextRow] = path[now.col][now.row] + 1;
			visited[nextCol][nextRow] = 1;
			q.push({ nextRow, nextCol });
			if (path[nextCol][nextRow] > MAX) MAX = path[nextCol][nextRow];
		}
	}
	return MAX;
}


int main() {
	cin >> Col >> Row;

	int M = -1;

	for (int i = 0; i < Col; i++) {
		for (int j = 0; j < Row; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < Col; i++) {
		for (int j = 0; j < Row; j++) {
			if (MAP[i][j]=='L') {
				int result=bfs(j, i);
				if (M < result) M = result;
				memset(visited, 0, sizeof(visited));
				memset(path, 0, sizeof(path));
			}
			
		}
	}
	cout << M;
	return 0;
}