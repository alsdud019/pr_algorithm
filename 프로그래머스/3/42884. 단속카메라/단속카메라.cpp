#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    if (a[1] <b[1]) return true;
    else return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);
    
    int camera=-300001;
    for (int i=0; i<routes.size(); i++){
        if (camera < routes[i][0]){
            camera=routes[i][1];
            answer++;
        }
    }
    
    
    return answer;
}