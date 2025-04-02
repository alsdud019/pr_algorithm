#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int first, sec, third;


bool check() {
	vector<int> vec;

	vec.push_back(first);
	vec.push_back(sec);
	vec.push_back(third);

	sort(vec.rbegin(), vec.rend());

	if (vec[0] >= vec[1] + vec[2]) return true;
	else return false;

}

int main() {

	while (1) {	
		cin >> first >> sec >> third;

		if (first == 0 && sec == 0 && third == 0) break;

		if (check()) {
			cout << "Invalid"<<'\n';
			continue;
		}

		if (first == sec && sec == third) cout << "Equilateral" << '\n';
		else if (first == sec || sec == third || first == third) cout << "Isosceles" << '\n';
		else cout << "Scalene" << '\n';
	}


	return 0;
}