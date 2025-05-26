#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
	if (a > b) return true;
	return false;
}

int main() {

	int N;
	cin >> N;

	int arr[27] = {0,};

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		int num = 1;
		for (int j = str.size() - 1; j >= 0; j--) {
			arr[str[j] - 'A'] += num;
			num *= 10;
		}
	}

	sort(arr,arr+26, cmp);

	int idx = 9;
	int answer = 0;
	for (int i = 0; i <26; i++) {
		answer+=arr[i] * idx;
		idx--;
	}

	cout << answer;





	return 0;
}