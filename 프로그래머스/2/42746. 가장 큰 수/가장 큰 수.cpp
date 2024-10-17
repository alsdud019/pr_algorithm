#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    if (a+b>b+a) return true;
    if (a+b<b+a) return false;
    return false;
}


string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> vec;
    
    for (int i=0; i<numbers.size(); i++){
        string temp=to_string(numbers[i]);
        vec.push_back(temp);
    }
    
    sort(vec.begin(), vec.end(), cmp);
    if (vec[0]=="0") return "0";
    
    for (int i=0; i<vec.size(); i++){
        answer+=vec[i];
    }
    
    return answer;
}