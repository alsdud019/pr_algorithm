#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int V, E;
int parent[10001];

int Find(int a) {
	if (parent[a] == a) return a;

	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	int u = Find(a);
	int v = Find(b);
	if (u==v) return;
	parent[u] = v;

}

int main() {

	cin >> V >> E;
	vector<pair<int, pair<int, int>>> vec;
	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		vec.push_back({ C,{A,B } });
	}

	for (int i = 0; i <= V; i++) {
		parent[i] = i;
	}

	sort(vec.begin(), vec.end());

	int cost = 0;
	for (int i = 0; i < vec.size(); i++) {
		int from = vec[i].second.first;
		int to = vec[i].second.second;
		if (Find(from) == Find(to))continue;
		Union(from, to);
		cost += vec[i].first;
	}

	cout << cost << '\n';
	return 0;
}