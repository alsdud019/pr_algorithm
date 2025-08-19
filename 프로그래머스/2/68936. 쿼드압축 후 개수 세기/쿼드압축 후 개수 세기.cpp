#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>>MAP;

int one=0;
int zero=0;

void recur(int y, int x, int length){
    
    int first=MAP[y][x];
    
    bool same=true;
    for (int i=y; i<y+length; i++){
        for (int j=x; j<x+length; j++){
            if (MAP[i][j]!=first) same=false;
        }
    }
    
    if (same){
        (first==0)? zero++: one++;
        return;
    }
    
    recur(y, x, length/2);
    recur(y, x+(length/2), length/2);
    recur(y+(length/2), x, length/2);
    recur(y+(length/2), x+(length/2), length/2);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    MAP=arr;
    
    recur(0,0,arr.size());
    
    answer={zero, one};
    
    
    return answer;
}