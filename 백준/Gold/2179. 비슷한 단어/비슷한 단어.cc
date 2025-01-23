#include <iostream>
#include <vector>

using namespace std;

int N;
vector<string> vec;


int main() {
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		vec.push_back(str);
	}

	int MAX = -1e9;
	string S, T;

	for (int i = 0; i < vec.size(); i++) {
		for (int j = i+1; j < vec.size(); j++) {

			int len = min(vec[i].size(), vec[j].size());


			int m=-1e9;
			for (int k = 0; k < len; k++) {
				if (vec[i][k] == vec[j][k]) {
					 m= k + 1;
				}
				else break;
			}

			if (MAX < m) {
				MAX = m;
				S = vec[i];
				T = vec[j];

			}
		}
	}

	cout << S << endl;
	cout << T << endl;

	return 0;
}