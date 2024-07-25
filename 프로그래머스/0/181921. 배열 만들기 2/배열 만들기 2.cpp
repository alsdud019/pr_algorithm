#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    for (int i=l; i<=r; i++){
        string str=to_string(i);
        int flag=0;
        for (int j=0; j<str.size(); j++){
            if (str[j]=='5' || str[j]=='0') flag=1;
            else {
                flag=0;
                break;
            }
        }
        if (flag) answer.push_back(i);
    }
    if (answer.size()<1){
        answer.push_back(-1);
    } 
    return answer;
}