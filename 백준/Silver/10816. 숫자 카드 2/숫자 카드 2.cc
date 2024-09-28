#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

using ll = long long;

unordered_map <int, int> m;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i= 0; i < N; i++) {
		int num;
		cin >> num;
		m[num]++;
	}
	int M;
	cin >> M;
	for (int j = 0; j < M; j++) {
		int num;
		cin >> num;
		cout << m[num] << " ";
	}


	return 0;
}