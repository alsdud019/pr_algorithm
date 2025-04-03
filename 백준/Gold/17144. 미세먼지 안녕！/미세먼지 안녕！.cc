#include <iostream>
#include <vector>

using namespace std;

int Y, X, T;
int map[51][51];

struct Node {
	int y;
	int x;
};
vector<Node> vec;

int calcul() {
	int sum = 0;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (map[i][j] == -1) continue;
			sum += map[i][j];
		}
	}
	return sum;
}

int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

void spray() {
	int dust_spray_map[51][51] = {0,};
	int dust_main_map[51][51] = {0,};

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (map[i][j] == -1) continue;
			if (map[i][j] == 0) continue;

			int d = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny<0 || nx<0 || ny>Y - 1 || nx>X - 1)continue;
				if (map[ny][nx] == -1) continue;

				int dust = map[i][j] / 5;
				dust_spray_map[ny][nx] += dust;
				d++;		
			}

			int remain = map[i][j] - ((map[i][j] / 5) * d);
			dust_main_map[i][j] = remain;
		}
	}

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (map[i][j] == -1) continue;
			map[i][j] = dust_main_map[i][j] + dust_spray_map[i][j];
		}
	}
}

void clean() {

	Node first_machine = vec[0];
	Node second_machine = vec[1];

	//시계 반대방향
	//맨 왼쪽, 아래 방향으로 내려오기 
	for (int i = first_machine.y - 2; i >= 0; i--) map[i+1][0] = map[i][0];
	//맨 위쪽, 왼쪽 방향으로 옮기기 
	for (int i = 1; i < X; i++) map[0][i-1] = map[0][i];
	//맨 오른쪽, 위쪽 방향으로 올리기 
	for (int i = 1; i <= first_machine.y; i++) map[i-1][X - 1] = map[i][X - 1];
	//아래쪽, 오른쪽 방향으로 옮기기 
	for (int i = X - 2; i >= 1; i--) map[first_machine.y][i+1] = map[first_machine.y][i];
	map[first_machine.y][1] = 0;

	//시계방향 
	//맨 왼쪽, 위쪽 방향으로 올리기 
	for (int i = second_machine.y + 2; i < Y; i++) map[i-1][0] = map[i][0];
	//맨 아래, 왼쪽 방향으로 옮기기 
	for (int i = 1; i < X; i++) map[Y - 1][i-1] = map[Y - 1][i];
	//맨 오른쪽, 아래 방향으로 내리기
	for (int i = Y - 1; i >= second_machine.y; i--) map[i+1][X - 1] = map[i][X - 1];
	//위쪽, 오른쪽 방향으로 옮기기 
	for (int i = X - 2; i >= 1; i--) map[second_machine.y][i+1] = map[second_machine.y][i];
	map[second_machine.y][1] = 0;
}


int main() {

	cin >> Y >> X >> T;

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				vec.push_back({ i,j });
			}
		}
	}

	while (T--) {
		spray();
		clean();
	}

	cout<<calcul();



	return 0;
}