#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int map[11][11];
int parent[11];

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

void bfs(int nowY, int nowX, int num) {

	queue<pair<int, int>> q;

	q.push({ nowY, nowX });
	map[nowY][nowX] = num;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny<0 || nx<0 || ny>N || nx>M) continue;
			if (map[ny][nx] == 0 || map[ny][nx]==num) continue;

			q.push({ ny,nx });
			map[ny][nx] = num;
		}
			
	}
}

struct Edge {
	int from;
	int to;
	int dist;
};

bool cmp(Edge A, Edge B) {
	if (A.dist < B.dist) return true;
	else return false;
}

vector<Edge> vec;

void length_count() {
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//섬을 발견하면 
			if (map[i][j] != 0) {
				int start = map[i][j];
				for (int k = 0; k < 4; k++) {
					int len = 0;
					int nowY = i;
					int nowX = j;
					while (1) {
						int ny = dy[k] + nowY;
						int nx = dx[k] + nowX;
						if (ny<0 || nx<0 || ny>N || nx>M || map[ny][nx] == start) break;
						if (map[ny][nx] == 0) {
							len++;
							nowY = ny;
							nowX = nx;
						}
						else {
							if (len >= 2) vec.push_back({ start, map[ny][nx],len });
							break;
						}
					}
				}
			}
		}
	}

}

int Find(int a) {
	if (parent[a] == a) return a;

	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	int n = Find(a);
	int m = Find(b);

	if (n == m) return;

	else parent[n] = m;
}


int main() {

	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) map[i][j] = -1;
		}
	}

	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] ==-1) {
				bfs(i, j,cnt);
				cnt += 1;
			}
		}
	}

	length_count();

	if (vec.size() < 1) {
		cout << -1;
		return 0;
	}

	sort(vec.begin(), vec.end(), cmp);


	for (int i = 1; i < cnt; i++) {
		parent[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		int from = vec[i].from;
		int to = vec[i].to;
		int cost = vec[i].dist;

		if (Find(from) == Find(to)) continue;

		Union(from, to);
		sum += cost;
	}

	int root = Find(1);
	for (int i = 1; i < cnt; i++) {
		if (root != Find(i)) {
			cout << -1;
			return 0;
		}
	}

	cout << sum;
	


}