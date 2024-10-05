#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int N;

char MAP[101][101];
int visited[101][101] = { 0, };
int ack_MAP[101][101];

struct Node {
	int row;
	int col;
};

void bfs(int stRow, int stCol) {
	queue<Node> q;

	q.push({ stRow, stCol });
	visited[stCol][stRow]=1;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		int dr[] = { 0,0,-1,1 };
		int dc[] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int nextRow = dr[i] + now.row;
			int nextCol = dc[i] + now.col;
			if (nextRow<0 || nextCol<0 || nextRow>N - 1 || nextCol>N - 1) continue;
			if (visited[nextCol][nextRow]) continue;
			if (MAP[nextCol][nextRow] == MAP[now.col][now.row]) {
				q.push({ nextRow, nextCol });
				visited[nextCol][nextRow]=1;
			}
		}

	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j= 0; j < N; j++) {
			cin >> MAP[i][j];
			
		}
	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				bfs(j, i);
				answer++;
			}

		}
	}
	cout << answer;
	cout << '\n';

	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] == 'R') MAP[i][j] = 'G';

		}
	}
	int answer_2=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				bfs(j, i);
				answer_2++;
			}
		}
	}
	cout << answer_2;

	
	return 0;
}