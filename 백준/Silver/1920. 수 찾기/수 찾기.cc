#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

int Binary_search(int num) {
	int left = 0; int right = vec.size()-1;

	while (left < right) {
		int mid = (left + right)/2;
		if (num < vec[mid]) {
			right = mid - 1;
		}
		else if (num > vec[mid]) {
			left = mid + 1;
		}
		else return mid;
	}

	return left;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; 
	cin >> N; 
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	int M; 
	cin >> M; 
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		if (vec[Binary_search(num)] == num) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}