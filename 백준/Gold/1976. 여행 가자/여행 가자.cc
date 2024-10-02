#include <iostream>
#include <vector>

using namespace std;
int N, M;

int parent[201];

int Find(int a) {
	if (parent[a] == a) return a;

	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	int u = Find(a);
	int v = Find(b);
	if (u == v) return;
	parent[u] = v;
}


int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int c;
			cin >> c;
			if (c) {
				Union(i, j);
			}
		}
	}
	
	int root;

	for (int i = 0; i < M; i++) {
		int route;
		cin >> route;
		if (i == 0) root = Find(route);
		else {
			if (Find(route) != Find(root)) {
				cout << "NO";
				return 0;
			}
		}

	}
	cout << "YES" << '\n';

	return 0;
}