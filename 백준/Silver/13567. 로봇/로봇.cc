#include <iostream>
#include <sstream>

using namespace std;

int robot_x, robot_y;
int arr[1001][1001];
int N, M;
int robot_d;

//오아왼위
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

void rotate(int toggle) {
	//시계방향
	if (toggle == 0) {
		robot_d++;
		if (robot_d > 3) robot_d = 0;
	}
	//반시계방향
	if (toggle == 1) {
		robot_d--;
		if (robot_d < 0) robot_d = 3;
	}
}

int main() {

	cin >> N >> M;
	robot_x = 0;
	robot_y = 0;

	for (int i = 0; i < M; i++) {
		string commend;
		cin >> commend;
		int num;
		cin >> num;

		if (commend == "TURN") {
			rotate(num);
		}
		else if (commend == "MOVE") {
			int distance = num;
			int nx = robot_x + dx[robot_d] * distance;
			int ny = robot_y + dy[robot_d] * distance;

			if (nx<0 || ny<0 || nx>N  || ny>N ) {
				cout << -1 << '\n';
				return 0;
			}
			robot_x = nx;
			robot_y = ny;
		}
	}
	cout << robot_x << " " << robot_y;

	return 0;
}