#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero_num=0;
    int correct_num=0;
    int ranking[7]={6,6,5,4,3,2,1};
    
    for (int i=0; i<lottos.size(); i++){
        if (lottos[i]==0) zero_num++;
        else if (find(win_nums.begin(), win_nums.end(),lottos[i])!=win_nums.end()) correct_num++;
    }
    
    answer.push_back(ranking[zero_num+correct_num]);
    answer.push_back(ranking[correct_num]);
    
    return answer;
}