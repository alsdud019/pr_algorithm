#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[101][101];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) map[i][j] = 0;
			else map[i][j] = 1e9;
		}
	}

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;

		map[A][B] = 1;
		map[B][A] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	vector<pair<int, int>>vec;
	for (int i = 1; i <= N; i++) {
		int res = 0;
		for (int j = 1; j <= N; j++) {
			if (map[i][j] >= 1e9) continue;
			else res+=map[i][j];
		}
		vec.push_back({ res,i });
	}

	sort(vec.begin(), vec.end());

	cout << vec[0].second;
	return 0;
}