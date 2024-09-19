#include <iostream>
#include <vector>
using namespace std;


vector <int> vec[4001];
int visited[4001] = { 0, };
bool flag = false;

void DFS(int node, int level) {
	if (level == 5 || flag) {
		flag = true;
		return;
	}
	for (int i = 0; i < vec[node].size(); i++) {
		int new_node = vec[node][i];
		if (visited[new_node]) continue;
		visited[new_node]=1;
		DFS(new_node, level + 1);
		visited[new_node] = 0;

	}
}

int main() {
	int node, edge;
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		int from, to;
		cin >> from >> to;
		vec[from].push_back(to);
		vec[to].push_back(from);
	}
	
	for (int i = 0; i < node; i++) {
        visited[i]=1;
		DFS(i, 1);
		if (flag) {
			break;
		}
        visited[i]=0;
	}
	if (!flag) cout << 0 << endl;
    else cout<<1<<endl;

	return 0;
}