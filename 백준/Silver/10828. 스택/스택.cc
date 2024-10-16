#include <iostream>
#include <vector>

using namespace std;
int N;


int main() {
	cin >> N;
	vector<long long > stack;
	while (N--) {
		string comd;
		cin >> comd;
		if (comd == "push") {
			long long num;
			cin >> num;
			stack.push_back(num);
		}
		else if (comd == "top") {
			if (stack.size() > 0) {
				cout << stack.back()<<'\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (comd == "pop") {
			if (stack.size() > 0) {
				cout << stack.back() << '\n';
				stack.pop_back();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (comd == "size") {
			cout << stack.size() << '\n';
		}
		else if (comd == "empty") {
			if (stack.size() > 0) {
				cout << 0 << '\n';
			}
			else {
				cout << 1 << '\n';
			}
		}



	}
	return 0;
}