#include <string>
#include <vector>
#include <cmath>

using namespace std;

using ll= long long;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(int i=1; i<=r2; i++){
        ll max_y=floor(sqrt((ll)r2*r2-(ll)i*i));
        ll min_y=ceil(sqrt((ll)r1*r1-(ll)i*i));
        
        if (i>r1) min_y=0;
        
        answer+=(max_y-min_y+1);
        
    }
    
    
    return answer*4;
}