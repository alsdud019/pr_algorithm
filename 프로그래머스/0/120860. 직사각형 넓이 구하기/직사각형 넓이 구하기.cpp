#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    int min_x=9999999; 
    int max_x=-999999;
    int min_y=9999999;
    int max_y=-999999;
    
    for (int i=0; i<dots.size(); i++){

        if (dots[i][0]<min_x) min_x=dots[i][0];
        if (dots[i][0]>max_x) max_x=dots[i][0];
        if (dots[i][1]<min_y) min_y=dots[i][1];
        if (dots[i][1]>max_y) max_y=dots[i][1];

    }
    answer=(max_x-min_x)*(max_y-min_y);
    // cout<<min_x<<" "<<max_x<<" "<<min_y<<" "<<max_y<<endl;
    
    return answer;
}