#include <iostream>
#include <vector>
using namespace std;

int N;
int main() {
	cin >> N;
	int ans = 0;

	while (N--) {
		string s;
		cin >> s;
		vector<char> stack;
		for (int i = 0; i < s.size(); i++) {
			if (stack.size() == 0) {
				stack.push_back(s[i]);
			}
			else if (s[i] == 'A') {
				if (stack.back() == 'A') {
					stack.pop_back();
				}
				else {
					stack.push_back(s[i]);
				}
			}
			else if (s[i] == 'B') {
				if (stack.back() == 'B') {
					stack.pop_back();
				}
				else {
					stack.push_back(s[i]);
				}
			}
		}
		if (stack.size() == 0) ans++;
	}
	cout << ans << '\n';
	return 0;
}