#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	vector<int> vec2 = vec;
	sort(vec2.begin(), vec2.end());
	vec2.erase(unique(vec2.begin(), vec2.end()),vec2.end());
	
	for (int i = 0; i < N; i++) {
		cout<<lower_bound(vec2.begin(), vec2.end(), vec[i]) - vec2.begin()<<" ";
	}



	return 0;
}