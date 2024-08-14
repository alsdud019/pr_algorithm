#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int c1_idx=0; int c2_idx=0;
    
    while (c1_idx+c2_idx<goal.size()){
        if (c1_idx<cards1.size() && cards1[c1_idx]==goal[c1_idx+c2_idx]){
            c1_idx++;
        }
        else if (c2_idx<cards2.size() && cards2[c2_idx]==goal[c1_idx+c2_idx]){
            c2_idx++;
        }
        else return "No";
    }
    
    return "Yes";
    // return answer;
}