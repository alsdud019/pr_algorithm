#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    while(n>0){
        int remain=n%3;
        
        if (remain==0){
            answer="4"+answer;
            n-=1;
        }
        else {
            answer=to_string(remain)+answer;
        }
        n/=3;
    }
    
    
    return answer;
}