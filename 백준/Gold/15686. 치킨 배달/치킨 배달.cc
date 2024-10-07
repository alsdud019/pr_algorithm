#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
struct Node{
	int y;
	int x;
};

vector<Node> house;
vector<Node> chicken;

int visited[14];
vector<Node> vec;

int cal() {
	int total = 0;
	for (int i = 0; i < house.size(); i++) {
		Node now_house = house[i];
		int hy = now_house.y;
		int hx = now_house.x;
		int my_min = 1e9;
		for (int j = 0; j < vec.size(); j++) {
			Node now_chicken = vec[j];

			int cy = now_chicken.y;
			int cx = now_chicken.x;
			int diff = abs(cy - hy) + abs(cx - hx);
			if (my_min > diff) my_min = diff;
		}
		total += my_min;
	}
	return total;
}

int MIN = 1e9;

void dfs(int level, int idx) {
	if (level == M) {
		int result=cal();
		if (MIN > result) MIN = result;
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		vec.push_back(chicken[i]);
		dfs(level + 1, i);
		visited[i] = 0;
		vec.pop_back();

	}
}

void Solution() {

	dfs(0,0);

}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int v;
			cin >> v;
			//집인경우 
			if (v == 1) {
				house.push_back({ i, j });
			}
			else if (v == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	Solution();

	cout << MIN;



	return 0;
}