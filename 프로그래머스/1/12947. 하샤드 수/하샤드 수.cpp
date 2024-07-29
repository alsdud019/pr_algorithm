#include <string>
#include <vector>


using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum=0;
    int who=x;
    while (who>0){
        sum+=who%10;
        who/=10;
    }

    if (x%sum==0) return true;
    else return false;

}