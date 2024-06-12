#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> answer;
    int coffee;
    coffee=money/5500;
    
    answer.push_back(coffee);
    int remain=money%5500;
    
    answer.push_back(remain);
    
    return answer;
}