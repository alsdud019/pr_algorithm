#include<iostream>
#include <vector>

using namespace std;

int N, M;
struct Edge {
	int end;
	int w;
};
vector<Edge> vec[501];
long long answer[501];

int main() {

	//입력받기 
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		vec[from].push_back({ to, w });
	}

	//벨만포드 
	//정답 배열 초기화 
	for (int i = 1; i <= N; i++) {
		answer[i] = 1e9;
	}
	answer[1] = 0;

	for (int i = 1; i <= N - 1; i++) {
		//시작점
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < vec[j].size(); k++) {
				int to = vec[j][k].end; //도착
				int weight = vec[j][k].w; //가중치

				if (answer[j] == 1e9) continue;
				if (answer[j] + weight < answer[to]) {
					answer[to] = answer[j] + weight;
				}

			}
		}
	}

	//한번더 실행해서 음수 사이클 여부 확인 
	for (int j = 1; j <= N; j++) {
		for (int k = 0; k < vec[j].size(); k++) {
			int to = vec[j][k].end; //도착
			int weight = vec[j][k].w; //가중치

			if (answer[j] == 1e9) continue;
			//만약 변경사항이 있다면 
			if (answer[j] + weight < answer[to]) {
				cout << -1 << endl;
				return 0;
			}

		}
	}

	//음수 사이클이 없다면
	for (int i = 2; i <= N; i++) {
		if (answer[i] == 1e9) cout << -1 << endl;
		else cout << answer[i] << endl;
	}



	return 0;
}