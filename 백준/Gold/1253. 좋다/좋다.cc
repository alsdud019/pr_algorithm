#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int arr[2001];
int cnt = 0;

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) cin >> arr[i];

	sort(arr, arr+N);

	for (int i = 0; i < N; i++) {
		int now = arr[i];

		int left = 0;
		int right = N - 1;

		while (left < right) {
			int sum = arr[left] + arr[right];
			if (sum > now) {
				right--;
			}
			else if (sum < now) {
				left++;
			}
			else { // 다른 두 수의 합이 현재 수랑 같을 때 
				if (left == i) {
					left++;
				}
				else if (right == i) {
					right--;
				}
				else if (sum == now) {
					cnt++;
					break;
				}
				
			}
		
		}
	}

	cout << cnt;


	return 0;
}