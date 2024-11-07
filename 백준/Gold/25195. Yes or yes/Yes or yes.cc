#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vec[100001];
int fan[100001];
int answer[100001];
int visited[100001] = { 0, };
int cnt = 0;


void DFS(int now, int level) {
	//해당 노드가 리프노드이면
	if (vec[now].size() == 0) {
		//for (int i = 0; i < level; i++) {
		//	cout << answer[i] << " ";
		//}
		//cout << '\n';
		cnt++;
		return;
	}

	for (int i = 0; i < vec[now].size(); i++) {
		int next = vec[now][i];
		if (fan[next] == 1) continue;

		if (visited[next] == 1) continue;
		visited[next] = 1;
		//answer[level] = next;
		DFS(next, level + 1);
		//answer[level] = 0;
		visited[next] = 0;
	}
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		vec[from].push_back(to);
	}

	int S;
	cin >> S;
	for (int i = 0; i < S; i++) {
		int num;
		cin >> num;
		fan[num] = 1;
	}


	if (fan[1] == 1) {
		cout << "Yes" << '\n';
		return 0;
	}
	visited[1] = 1;
	//answer[0] = 1;
	DFS(1, 1);

	//안만난다. 
	if (cnt > 0) {
		cout << "yes" << '\n';
	}
	//만난다. 
	else {
		cout << "Yes" << '\n';
	}

	return 0; 
}