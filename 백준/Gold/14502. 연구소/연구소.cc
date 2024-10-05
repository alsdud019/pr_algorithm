#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int Col, Row;
int MAP[9][9];
int visited[9][9];
int MAX = -1;
int ans = 0;

struct Node {
	int row;
	int col;
};

void bfs() {

	queue<Node> q;
	int MAP2[9][9];

	for (int i = 0; i < Col; i++) {
		for (int j = 0; j < Row; j++) {
			MAP2[i][j] = MAP[i][j];
			if (MAP2[i][j] == 2) {
				q.push({ j,i });
				visited[i][j] = 1;
			}
			
		}
	}

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		int dr[] = { 0,0,-1,1 };
		int dc[] = { -1,1,0,0 };
		for (int i = 0; i < 4; i++) {
			int nextRow = now.row + dr[i];
			int nextCol = now.col + dc[i];

			if (nextCol<0 || nextRow<0 || nextCol>Col - 1 || nextRow>Row - 1)continue;
			if (MAP2[nextCol][nextRow]!=0) continue;
			if (visited[nextCol][nextRow]) continue;
			
			visited[nextCol][nextRow] = 1;
			MAP2[nextCol][nextRow] = 2;
			q.push({ nextRow, nextCol });
		}
	}

	
	int cnt = 0;
	for (int i = 0; i < Col; i++) {
		for (int j = 0; j < Row; j++) {
			if (MAP2[i][j] == 0) cnt++;
		}
	}
	if (MAX < cnt) MAX = cnt;

	memset(visited, 0, sizeof(visited));

	
}

void dfs( int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	if (cnt > 3) return;
	for (int i = 0; i < Col; i++) {
		for (int j = 0; j < Row; j++) {

			if (MAP[i][j] != 0) continue;
			MAP[i][j] = 1;
			dfs(cnt + 1);
			MAP[i][j] = 0;
		}
	}
	
}

int main() {
	cin >> Col >> Row;

	for (int i = 0; i < Col; i++) {
		for (int j = 0; j < Row; j++) {
			cin >> MAP[i][j];
		}
	}

	dfs(0);
	cout << MAX;

	return 0;
}