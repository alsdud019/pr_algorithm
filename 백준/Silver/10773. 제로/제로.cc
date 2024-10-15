#include <iostream>
#include <vector>

using namespace std;

int K;

int main() {

	cin >> K;
	vector<int> stack;
	while (K--) {
		int num;
		cin >> num;
		if (num != 0) {
			stack.push_back(num);
		}
		else if (num == 0) {
			if (stack.size() != 0) {
				stack.pop_back();
			}
			else if (stack.size() == 0) {
				continue;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < stack.size(); i++) {
		sum += stack[i];
	}
	cout << sum;

	return 0;
}