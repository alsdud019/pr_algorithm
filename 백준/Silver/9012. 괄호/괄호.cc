#include <iostream>
#include <vector>

using namespace std;

int T;

int main() {

	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		vector<char>stack;
		bool flag = true;
		for (int i = 0; i < s.size(); i++) {
			//cout << s[i] << " ";
			if (s[i] == '(') {
				stack.push_back(s[i]);
			}
			else if (s[i] == ')') {
				if (stack.size() == 0) {
					flag = false;
					break;
				}
				else if (stack.size() != 0) {
					stack.pop_back();
				}
			} 
		}
		if (stack.size() != 0 || flag==false) cout << "NO"<<'\n';
		else cout << "YES" << '\n';
	}

	return 0;
}