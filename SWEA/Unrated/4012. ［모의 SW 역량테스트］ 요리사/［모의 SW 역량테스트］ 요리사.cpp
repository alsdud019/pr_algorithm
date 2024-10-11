#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int T;
int N;
int arr[17][17];
int visited[17];
int MIN;

void init() {
	memset(arr, 0, sizeof(arr));
	memset(visited, 0, sizeof(visited));
	MIN = 1e9;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

}
void Calcul() {
	vector<int> a;
	vector<int> b;
	int a_sum = 0;
	int b_sum = 0;
	for (int i = 0; i < N; i++) {
		if (visited[i] == 1) {
			a.push_back(i);
		}
		else if (visited[i] == 0) {
			b.push_back(i);
		}
	}

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			if (a[i] == a[j]) continue;
			a_sum += arr[a[i]][a[j]];
		}
	}
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (b[i] == b[j]) continue;
			b_sum += arr[b[i]][b[j]];
		}
	}

	int m = abs(a_sum - b_sum);
	if (MIN > m) MIN = m;


}

void DFS(int level, int idx) {

	if (level >= N / 2) {
		//for (int i = 0; i < N; i++) {
		//	if (visited[i] == 1) {
		//		cout << i << " ";
		//	}
		//}
		//cout << endl;
		Calcul();
		return;
	}

	for (int i = idx; i < N; i++) {
		if (visited[i] == 1) continue;
		visited[i] = 1;
		DFS(level+1, i);
		visited[i] = 0;
	}
}

void Solution() {
	DFS(0, 0);
}

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		init();
		Solution();
		cout << '#' << i<<" " << MIN<<'\n';
	}
	return 0;
}