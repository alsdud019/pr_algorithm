#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int N, K,S,X,Y;

int MAP[201][201];
int visited[201][201];;

struct Node {
	int time;
	int value;
	int row;
	int col;
};

struct newop {
	bool operator()(Node left, Node right) const {
		if (left.time < right.time) return false;
		if (left.time > right.time) return true;

		if (left.value < right.value) return false;
		if (left.value > right.value) return true;

		return false;
	}

};

priority_queue<Node, vector<Node>, newop> pq;

void bfs() {
	
	while (!pq.empty()) {

		Node now = pq.top(); pq.pop();

		int dr[] = { 0,0,-1,1 };
		int dc[] = { 1,-1,0,0 };

		if (now.time > S) return;

		for (int i = 0; i < 4; i++) {
			int nextRow = now.row + dr[i];
			int nextCol = now.col + dc[i];
			int time = now.time;

			if (nextRow<0 || nextCol<0 || nextRow>N - 1 || nextCol>N - 1) continue;
			if (visited[nextCol][nextRow])continue;

			visited[nextCol][nextRow] = 1;
			MAP[nextCol][nextRow] = MAP[now.col][now.row];
			pq.push({ time+1, MAP[nextCol][nextRow], nextRow, nextCol });
			

		}
	}
	


}

int main() {

	cin >> N >> K;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] > 0) {
				pq.push({1, MAP[i][j], j,i });
				visited[i][j] = 1;
			}
		}
	}

	cin >> S >> X >> Y;

	bfs();

	cout << MAP[X-1][Y-1];


	return 0;
}