#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
int N;
int LOVE[401][401];
int student[401];
int MAP[21][21];


int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };



struct info {
	int like;
	int bin;
	int y;
	int x;
};

struct cmp {
	bool operator () (info left, info right) const {
		if (left.like < right.like) return true;
		if (left.like > right.like) return false;

		if (left.bin < right.bin) return true;
		if (left.bin > right.bin) return false;

		if (left.y < right.y) return false;
		if (left.y > right.y) return true;

		if (left.x < right.x) return false;
		if (left.x > right.x) return true;
		return false;
	}
};


void Compare(int idx) {
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//비어있는 경우 
			if (MAP[i][j] == 0) {
				int like = 0;
				int bin = 0;
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (nx<0 || ny<0 || nx>N - 1 || ny>N - 1)continue;
					if (MAP[ny][nx] != 0 && LOVE[idx][MAP[ny][nx]] == 1) like++;
					if (MAP[ny][nx] == 0) bin++;
				}
				pq.push({ like, bin, i, j });
			}
		}
	}
	info select = pq.top();
	//cout << select.y<<select.x << endl;
	MAP[select.y][select.x] = idx;
}

long long sum = 0;

void Prefer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int me = MAP[i][j];
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (nx<0 || ny<0 || nx>N - 1 || ny>N - 1)continue;
				if (LOVE[me][MAP[ny][nx]] == 1) cnt++;

			}
			if (cnt > 0) sum += pow(10, cnt - 1);
		}
	}
}

void Arange() {
	for (int i = 1; i <= N * N; i++) {
		Compare(student[i]);
	}

	Prefer();
}

int main() {

	
	cin >> N;
	for (int i = 1; i <= N * N; i++) {
		cin >> student[i];
		
		for (int j = 0; j < 4; j++) {
			int to;
			cin >> to;
			LOVE[student[i]][to]=1;
		}
	}

	Arange();

	cout << sum;



	return 0;
}