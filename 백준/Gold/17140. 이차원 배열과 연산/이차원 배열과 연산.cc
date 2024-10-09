#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>

using namespace std;
int R = 3;
int C = 3;
int r, c, k;

int MAP[101][101];
int TIME = 0;


bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second < b.second) return true;
	if (a.second > b.second) return false;

	if (a.first < b.first) return true;
	if (a.first > b.first) return false;

	return false;
}

//행 연산
int R_cal() {
	int maxC = -9999;
	for (int i = 0; i < R; i++) {
		//첫번째 행 
		int DAT[101] = {0,};
		
		unordered_map<int, int>m;
		for (int j = 0; j < C; j++) {
			if (MAP[i][j] < 1) continue;
			DAT[MAP[i][j]]++;
		}
		for (int k = 1; k < 101; k++) {
			if (DAT[k] > 0) {
				m.insert({ k, DAT[k] });
			}
		}
		vector<pair<int, int>>vec(m.begin(), m.end());
		sort(vec.begin(), vec.end(), cmp);
		memset(MAP[i], 0, sizeof(MAP[i]));

		for (int n = 0; n < vec.size(); n++) {
			if (n*2<100) MAP[i][n * 2] = vec[n].first;
			if (n*2+1 <100) MAP[i][n * 2 + 1] = vec[n].second;
			
		}
		int row = m.size() * 2;
		maxC = max(maxC, min(100, row));
	}

	return maxC;

}

//열 연산
int C_cal() {
	int maxR = -9999;
	for (int i = 0; i < C; i++) {
		int DAT[101] = { 0, };
		vector<pair<int, int>>vec;
		for (int j = 0; j < R; j++) {
			if (MAP[j][i] > 0) {
				DAT[MAP[j][i]]++;
			}
		}
		for (int k = 1; k < 101; k++) {
			if (DAT[k] > 0) vec.push_back({ k, DAT[k] });
		}

		sort(vec.begin(), vec.end(), cmp);
		for (int n = 0; n < 100; n++) {
			MAP[n][i] = 0;
		}
		for (int m = 0; m < vec.size(); m++) {
			if (m * 2 < 100) MAP[m * 2][i] = vec[m].first;
			if (m * 2 + 1 < 100) MAP[m * 2 + 1][i] = vec[m].second;
		}
		int col = vec.size() * 2;
		maxR=max(maxR,min(100, col));
		
	}
	return maxR;
}

bool toggle = true;
void Solution() {

	while (1) {
		if (MAP[r - 1][c - 1] == k) break;
		if (TIME >= 100) {
			toggle = false;
			break;
		}

		if (R >= C) {
			C = R_cal();
			TIME++;
		}
		else {
			R = C_cal();
			TIME++;
		}

	}
	if (toggle) cout << TIME;
	else cout << -1;
	
}

int main() {

	
	cin >> r >> c >> k;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> MAP[i][j];
		}
	}

	Solution();


	return 0;
}