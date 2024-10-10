#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int MAP[51][51];
struct Node {
	int y;
	int x;
};

int visited[11];
int visited2[51][51];
vector<Node> virous;
vector<Node> vec;
int zero = 0;

int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

int MIN = 1e9;
void bfs() {
	memset(visited2, 0, sizeof(visited2));
	int check = 0;
	int m = 0;
	queue<Node> q;

	for (int i = 0; i < virous.size(); i++) {
		if (visited[i] == 1) {
			q.push(virous[i]);
			visited2[virous[i].y][virous[i].x] = 1;
		}
	}

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;

			if (ny<0 || nx<0 || ny>N - 1 || nx>N - 1)continue;
			if (MAP[ny][nx] !=1 && visited2[ny][nx] == 0) {

				visited2[ny][nx] = visited2[now.y][now.x] + 1;
				if (MAP[ny][nx] == 0) {
					check++;
					m = visited2[ny][nx];
				}
				q.push({ ny,nx });
			}
		}

	}
	if (check == zero) {
		MIN = min(m-1, MIN);
	}
	//return m - 1;
}


void DFS(int level, int idx) {

	if (level == M) {
		//for (int i = 0; i < virous.size(); i++) {
		//	if (visited[i] == 1) {
		//		cout << i << " ";
		//	}
		//	
		//}
		//cout << endl;
		bfs();
		return;
	}

	for (int i = idx; i < virous.size(); i++) {
		if (visited[i] == 1) continue;

		//vec.push_back(virous[i]);
		visited[i] = 1;
		DFS(level + 1, i);
		visited[i] = 0;
		//vec.pop_back();
	}
}

void Solution() {

	DFS(0,0);
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				virous.push_back({ i,j });
			}
			if (MAP[i][j] == 0) zero++;
			
		}
	}

	Solution();

	if (MIN >= 1e9) cout << -1;
	else if (MIN == -1) cout << 0;
	else {
		cout << MIN;
	}


	return 0;
}