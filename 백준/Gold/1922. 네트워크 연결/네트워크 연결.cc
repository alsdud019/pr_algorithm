#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int parent[1001];

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
	vector < pair<int, pair<int, int>>> vec;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >>  c;
		vec.push_back({ c,{a,b} });
	}

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	sort(vec.begin(), vec.end());
	int sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		int from = vec[i].second.first;
		int to = vec[i].second.second;
		

		if (Find(from) == Find(to)) continue;
		Union(from, to);
		sum += vec[i].first;
	}
	cout << sum;

	return 0;
}
