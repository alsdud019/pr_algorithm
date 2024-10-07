#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	string original;
	getline(cin, original);

	string ans;
	for (int i = 0; i < original.size(); i++) {
		char now = original[i];
		if (now == '<') {
			string tag;
			int idx = 0;
			while (1) {
				tag += original[i + idx];
				if (original[i + idx] == '>') {
					break;
				}
				idx++;
			}
			i += idx;
			ans += tag;
		}
		else if (now == ' ') ans += ' ';
		else {
			//문자일 때 
			vector<char> word;
			int idx = 0;
			while (1) {
				if (original[i + idx] == ' ' || i + idx == original.size() || original[i + idx]=='<') {
					idx--;
					break;
				}
				word.push_back(original[i + idx]);
				idx++;
			}
			i += idx;
			for (int i = 0; i < word.size(); i++) {
				/*ans += word.back();
				word.pop_back();*/
				ans+=word[word.size() - i - 1];
			}
		}

	}
	cout << ans;
	return 0;
}