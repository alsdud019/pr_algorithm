#include <iostream>
#include <vector>

using namespace std;

int N, M;
int vec[1000001];

int Find(int a) {
	if (vec[a] == a) {
		return a;
	}
	return vec[a] = Find(vec[a]);
}

void Union(int a, int b) {
	int u = Find(a);
	int v = Find(b);

	if (u == v) return;

	vec[u] = v;

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for (int i = 0; i <= N; i++) {
		vec[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int toggle, a, b;
		cin >> toggle >> a >> b;

		if (!toggle) {
			Union(a, b);
		}
		else {
			if (Find(a) == Find(b)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}

	}
	return 0;
}