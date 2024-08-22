#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> vec={-1};
    for (int i=0; i<ingredient.size(); i++){

        if (vec.back()==1 && ingredient[i]==2) vec.back()=12;
        else if (vec.back()==12 && ingredient[i]==3) vec.back()=123;
        else if (vec.back()==123 && ingredient[i]==1) {
            answer++;
            vec.pop_back();
        }
        else vec.push_back(ingredient[i]);
        
    }
    return answer;
}