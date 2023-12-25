#include <string>
#include <vector>
#include <iostream>

using namespace std;
char op[2]={'+','-'};

int levelNum;
char used[21];
int cnt;
int targetNum;

void dfs(int level, vector <int> numbers) {

    if (level > levelNum) {
        return; 
    }

    if (level == levelNum) {
        int sum=0;
        for (int i = 0; i < levelNum; i++) {
            if (used[i] == '+') {
                sum += numbers[i];
            }
            else if (used[i] == '-') {
                sum -= numbers[i];
            }
            //cout << used[i] <<numbers[i];
        }
        if (sum == targetNum) {
            cnt++;
        }
        //cout << sum << endl;
        //cout << endl;
        return;
    }

    for (int i = 0; i < 2; i++) {

        used[level] = op[i];
        dfs(level + 1,numbers);
        used[level] = '0';

    }
}

int solution(vector<int> numbers, int target) {
    //int answer = 0;
    levelNum=numbers.size();
    targetNum=target;
    dfs(0,numbers);
    return cnt;
}