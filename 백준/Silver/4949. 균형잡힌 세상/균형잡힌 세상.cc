#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	while (1) {
		string s;
		getline(cin, s);
		vector<char> stack;
		if (s == ".") break;
		bool flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[') {
				stack.push_back(s[i]);
			}
			else if (s[i] == ']') {
				if (stack.size() != 0 && stack.back() == '[') {
					stack.pop_back();
				}
				else {
					flag = false;
					break;
				}
			}
			else if (s[i] == ')') {
				if (stack.size()!=0 && stack.back() == '(') {
					stack.pop_back();
				}
				else {
					flag = false;
					break;
				}
			}
		}
		if (flag == false || stack.size() != 0) cout << "no" << '\n';
		else cout << "yes" << '\n';
	}
	return 0;
}