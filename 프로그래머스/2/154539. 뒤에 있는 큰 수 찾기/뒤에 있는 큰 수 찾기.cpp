#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    vector<int> stack;
    
    for (int i=numbers.size()-1; i>=0; i--){
        while(1){
            if (stack.empty()){
                answer[i]=-1;
                break;
            }
            if (numbers[i]<stack.back()){
                answer[i]=stack.back();
                break;
            }
            stack.pop_back();
        }
        stack.push_back(numbers[i]);
    }
    return answer;
}