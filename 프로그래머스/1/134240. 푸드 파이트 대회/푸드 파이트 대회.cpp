#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    vector<int> how;
    for (int i=0; i<food.size(); i++){
        if (i==0) continue;
        int how_much=food[i]/2;
        how.push_back(how_much);
    }
    for (int i=0; i<how.size(); i++){
        for (int j=0; j<how[i]; j++){
            answer+=(to_string(i+1));
        }
    }
    answer+='0';
    for (int i=how.size()-1; i>-1; i--){
        for (int j=0; j<how[i]; j++){
            answer+=(to_string(i+1));
        }
    }    
    return answer;
}