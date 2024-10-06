#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int MAP[51][51];
int DAT[51][51];

int dy[] = {0,0,-1,-1,-1,0,1,1,1};
int dx[] = {0, -1,-1,0,1,1,1,0,-1};

struct Node {
	int y;
	int x;
};

struct move_info {
	int d;
	int s;
};
vector<Node> cloud;
vector<move_info> path;

int check(int x) {
	if (x < 0) return N - 1;
	if (x > N - 1) return 0;
	return x;
}

void move(int idx) {
	move_info p = path[idx];
	int d = p.d;
	int s = p.s;

	memset(DAT, 0, sizeof(DAT));
	for (int i = 0; i < cloud.size(); i++) {
		Node now = cloud[i];

		int ny = now.y;
		int nx = now.x;
		for (int j = 0; j < s; j++) {
			ny += dy[d];
			nx += dx[d];
			ny = check(ny);
			nx = check(nx);

		}
		cloud[i].x = nx;
		cloud[i].y = ny;
		
	}


}

void rain() {
	for (int i = 0; i < cloud.size(); i++) {
		Node now = cloud[i];
		MAP[now.y][now.x]++;
		DAT[now.y][now.x] = 1;
	}
}

void Copy() {
	for (int i = 0; i < cloud.size(); i++) {
		Node now = cloud[i];
		int cnt = 0;
		for (int j = 2; j <= 8; j += 2) {
			int ny = now.y + dy[j];
			int nx = now.x + dx[j];
			if (ny<0 || nx<0 || ny>N - 1 || nx>N - 1) continue;
			if (MAP[ny][nx] > 0) cnt++;
		}
		MAP[now.y][now.x] += cnt;
	}
}

void make_cloud() {
	cloud.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (DAT[i][j])continue;
			if (MAP[i][j] >= 2) {
				MAP[i][j] -= 2;
				cloud.push_back({ i,j });
			}
		}
	}

	memset(DAT, 0, sizeof(DAT));
	for (int i = 0; i < cloud.size(); i++) {
		Node now = cloud[i];
		DAT[now.y][now.x]=1;
	}
}


void Rain() {

	for (int i = 0; i < M; i++) {
		move(i);
		rain();
		Copy();
		make_cloud();
	}
	
}



int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int d, s;
		cin >> d >> s;
		path.push_back({ d,s });
	}
	cloud.push_back({ N - 1, 0 });
	cloud.push_back({ N-1, 1 });
	cloud.push_back({ N - 2, 0 });
	cloud.push_back({ N - 2, 1 });

	DAT[N - 1][0] = 1;
	DAT[N - 1][1] = 1;
	DAT[N - 2][0]=1;
	DAT[N - 2][1]=1;


	Rain();

	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum += MAP[i][j];
		}
	}
	cout << sum;


	return 0;
}
