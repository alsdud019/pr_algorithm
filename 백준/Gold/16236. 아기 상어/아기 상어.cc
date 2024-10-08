#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int N;

int MAP [21][21];
int sharkx;
int sharky;
int sharkw;
int fish_eat = 0;
int sec=0;

//상하좌우
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

struct fish {
	int fishy;
	int fishx;
	int fishw; //물고기 무게 
	int fishd; //물고기 까지 거리 
};

struct newoperator {
	bool operator()(fish left, fish right) {
		//거리가 작은게 우선 
		if (left.fishd < right.fishd) return false;
		if (left.fishd > right.fishd) return true;

		//행이 작은게 우선
		if (left.fishy < right.fishy) return false;
		if (left.fishy > right.fishy) return true;

		//열이 작은게 우선 
		if (left.fishx < right.fishx) return false;
		if (left.fishx > right.fishx) return true;
		
		//같은경우
		return false;
	}
};

priority_queue<fish,vector<fish>, newoperator> bobq;

struct Node {
	int y;
	int x;
};

int visited[21][21];
int bfs(int endCol, int endRow) {

	int stCol = sharky;
	int stRow = sharkx;

	queue<Node> q;
	q.push({ stCol, stRow });
	visited[stCol][stRow] = 1;

	while (!q.empty()) {

		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nextRow = now.x + dx[i];
			int nextCol = now.y + dy[i];

			if (nextRow < 0 || nextCol<0 || nextRow>N - 1 || nextCol > N - 1)continue;
			if (visited[nextCol][nextRow])continue;
			//자기 보다 큰 물고기를 만나면 
			if (sharkw < MAP[nextCol][nextRow])continue;

			q.push({ nextCol, nextRow });
			visited[nextCol][nextRow] = visited[now.y][now.x] + 1;

			//if (nextCol == endCol && nextRow == endRow) break;

		}
		

	}
	return visited[endCol][endRow] - 1;

}

void Solution() {

	while (true) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//만약 물고기가 존재하는데, 지금 상어 무게보다 작다면 
				if (0 < MAP[i][j] && MAP[i][j] < sharkw) {

					int d = bfs(i, j);
					memset(visited, 0, sizeof(visited));

					//물고기까지 도달 불가능이면 
					if (d < 0) continue;

					//값이 양수이면, 물고기까지 도달 가능하면, 먹을 수 있는 물고기 이면
					if (d > 0) bobq.push({ i,j,MAP[i][j],d });
				}
			}
		}

		//먹을 물고기가 없다면
		if (bobq.size() < 1) break;

		else {
			fish my_bob=bobq.top();
			//상어 위치 이동
			MAP[sharky][sharkx] = 0;

			sharky = my_bob.fishy;
			sharkx = my_bob.fishx;

			//먹기, 칸 비우기  
			MAP[my_bob.fishy][my_bob.fishx] = 0;
			fish_eat++;

			//몸키우기 
			if (fish_eat == sharkw) {
				sharkw++;
				fish_eat = 0;
			}


			//먹기 바구니 비우기
			bobq = priority_queue<fish,vector<fish>,newoperator>();
			
			//먹기까지 걸린 시간 더해주기
			sec += my_bob.fishd;

		}
	}



}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 9) {
				sharky = i;
				sharkx = j;
			}
		}
	}

	sharkw = 2;

	Solution();

	cout << sec;

	return 0;
}