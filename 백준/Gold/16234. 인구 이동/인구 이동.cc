#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, L, R;
int contry[51][51];
int visited[51][51];
int sum = 0;

struct Node {
	int row;
	int col;
};

vector<Node>vec;


void bfs(int stRow, int stCol) {
	
	queue<Node>q;

	vec.push_back({ stRow,stCol });
	sum = contry[stCol][stRow];
	visited[stCol][stRow] = 1;

	q.push({ stRow, stCol });
	
	while (!q.empty()) {

		Node now = q.front(); q.pop();

		int dr[] = { 0,0,-1,1 };
		int dc[] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int nextRow = now.row + dr[i];
			int nextCol = now.col + dc[i];

			if (nextCol<0 || nextRow<0 || nextRow>N - 1 || nextCol>N - 1)continue;
			if (visited[nextCol][nextRow])continue;

			if (L <= abs(contry[nextCol][nextRow] - contry[now.col][now.row]) && abs(contry[nextCol][nextRow] - contry[now.col][now.row]) <= R) {
				visited[nextCol][nextRow] = 1;
				sum += contry[nextCol][nextRow];
				vec.push_back({ nextRow, nextCol });

				q.push({ nextRow, nextCol });
			}

		}
	}

}

int main() {

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> contry[i][j];
		}
	}
	int day = 0;
	int flag = true;

	while (flag) {
		flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]) continue;
				bfs(j, i);

				if (vec.size() > 1) {
					for (int i = 0; i < vec.size(); i++) {
						int r = vec[i].row;
						int c = vec[i].col;
						contry[c][r] = sum / vec.size();
					}
					flag = true;
				}
				vec.clear();
			}
		}
		if (flag) day++;
		memset(visited, 0, sizeof(visited));
	}

	cout << day;

	return 0;
}