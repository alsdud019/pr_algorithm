#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T;
int N;
struct Node {
	int x;
	int y;

};
vector<Node> vec;
int visited[11];
int endX, endY;
int MIN;
int stX, stY;

void DFS(int nowX, int nowY, int sum, int level) {

	if (level >= N) {
		sum+=(abs(endX - nowX) + abs(endY - nowY));
		if (MIN > sum) {
			MIN = sum;
			//cout << sum << endl;
		}
		return;
	}

	if (sum > MIN) return;

	for (int i = 0; i < vec.size(); i++) {
		if (visited[i] == 1) continue;

		Node next = vec[i];
		int diff = abs(next.x - nowX) + abs(next.y - nowY);

		visited[i] = 1;
		DFS(next.x, next.y, sum+diff, level+1);
		visited[i] = 0;
	}
}

void init() {
	vec.clear();
	memset(visited, 0, sizeof(visited));
	MIN = 1e9;

	cin >> N;

	cin >> stX >> stY;
	cin >> endX >> endY;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		vec.push_back({ x,y });
	}
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> T;

	for (int j=1; j<=T; j++) {
		init();
		DFS(stX, stY,0,0);
		cout << '#' << j << " " << MIN << endl;
	}

	return 0;
}