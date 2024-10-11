#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
struct Fireball {
	int y;
	int x;
	int m;
	int s;
	int d;
};
vector<Fireball> MAP[51][51];
vector<Fireball>ball_list;

int dy[] = { -1,-1,0,1,1,1,0,-1 };
int dx[] = { 0,1,1,1,0,-1,-1,-1 };

void ball_move() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			MAP[i][j].clear();
		}
	}

	for (int i = 0; i < ball_list.size(); i++) {
		Fireball now = ball_list[i];

		int s = now.s % N;
		int ny = now.y + dy[now.d]*s;
		int nx = now.x + dx[now.d]*s;
		if (ny < 0) ny += N;
		if (nx < 0) nx += N;
		if (ny > N-1)ny -= N;
		if (nx > N-1)nx -= N;

		ball_list[i] = { ny,nx,now.m,now.s,now.d };
		MAP[ny][nx].push_back({ ny,nx,now.m,now.s,now.d });

	}
}

void ball_cal() {

	vector<Fireball> Temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			int size = MAP[i][j].size();
			if (size < 1) continue;
			if (size == 1) {
				Temp.push_back(MAP[i][j][0]);
				continue;
			}

			int m_sum = 0;
			int s_sum = 0;
			bool hol = true;
			bool jak = true;

			for (int k = 0; k < size; k++) {
				Fireball now = MAP[i][j][k];
				m_sum += now.m;
				s_sum += now.s;

				if (now.d % 2 == 0) jak = false;
				else hol = false;
			}

			int m = m_sum / 5;
			int s = s_sum / size;
			if (m == 0) continue;
			if (jak == true || hol == true) {
				for (int d = 0; d <= 6; d += 2) {
					Temp.push_back({ i,j,m,s,d });
				}
			}
			else  {
				for (int d = 1; d <= 7; d += 2) {
					Temp.push_back({ i,j,m,s,d });
				}
			}
			
		}
	}
	ball_list = Temp;
}

void Solution() {
	for (int i = 0; i < K; i++) {
		ball_move();
		ball_cal();
	}
}


int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int y, x, m, s, d;
		cin >> y >> x >> m >> s >> d;
		MAP[y][x].push_back({ y,x,m,s,d });
		ball_list.push_back({ y,x,m,s,d });
	}

	Solution();

	int ans = 0;
	for (int i = 0; i < ball_list.size(); i++) {
		ans += ball_list[i].m;
	}

	cout << ans;
	return 0;
}