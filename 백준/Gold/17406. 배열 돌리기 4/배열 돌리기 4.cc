#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;

int arr[51][51];
int answer = 1e9;;

struct info {
	int c;
	int s;
	int r;
};

vector<info> vec;
int used[7] = {0,};

void copy(int arr[51][51], int brr[51][51]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			brr[i][j] = arr[i][j];
		}
	}
}

void recover(int arr[51][51], int brr[51][51]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			arr[i][j] = brr[i][j];
		}
	}
}

void rotate(int arr[51][51], info info) {
	int c = info.c;
	int s = info.s;
	int r = info.r;

	//사각형의 개수 만큼 실행((c+s-(c-s))/2=s)
	for (int k = 0; k < s; k++) {

		//4변에 대해서 
		int left_y = r - s + k;
		int left_x = c - s + k;
		int right_y = r + s - k;
		int right_x = c + s - k;

		int first = arr[left_y][left_x];
		for (int i = left_y +1; i <= right_y; i++) arr[i - 1][left_x] = arr[i][left_x];
		for (int i = left_x + 1; i <= right_x; i++) arr[right_y][i - 1] = arr[right_y][i];
		for (int i = right_y - 1; i >= left_y; i--) arr[i+1][right_x] = arr[i][right_x];
		for (int i = right_x - 1; i >= left_x+1; i--) arr[left_y][i+1] = arr[left_y][i];
		arr[left_y][left_x+1] = first;

	}

}

int MIN = 1e9;

void dfs(int level, int arr[51][51]) {

	//종료조건- 맵 연산하기 
	if (level == K) {
		for (int i = 1; i <=N; i++) {
			int sum = 0;
			for (int j = 1; j <= M; j++) {
				sum += arr[i][j];
			}
			answer = min(sum, answer);
		}
		MIN = min(answer, MIN);
		return;
	}

	for (int i = 0; i < vec.size(); i++) {
		info next = vec[i];
		if (used[i]) continue;

		//연산방법 하나 뽑기 
		used[i] = 1;

		//현재 맵 복사해두기
		int brr[51][51] = {0,};
		copy(arr, brr);

		//맵 돌리기
		rotate(arr, next);	

		dfs(level + 1, arr);

		//맵 다시 되돌리기 
		recover(arr, brr);

		used[i] = 0;

	}
}


int main() {

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int c, s, r;
		cin >> r >> c >> s;
		vec.push_back({ c,s,r });
	}

	dfs(0, arr);
	
	cout << MIN;

	return 0;
}
