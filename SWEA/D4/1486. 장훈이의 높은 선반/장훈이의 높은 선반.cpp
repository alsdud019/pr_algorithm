#include <iostream>
#include<algorithm> 
#include<queue>
#include<vector>
#include <string.h>
 
 
using namespace std;
 
int height[21];
 
int N, B;
int used[21];
int MIN;
 
void init() {
    memset(used, 0, sizeof(used));
    memset(height, 0, sizeof(height));
    MIN = 999999;
 
}
 
void recur(int num, int now) {
     
    if (now >= B) {  
        int min = now - B;
        if (MIN > min) MIN = min;
        return;
        //cout << now-B << endl;
    }
 
    if (num == N) return;
 
    //숫자를 뽑을 때 
    recur(num+1, now + height[num]);
 
    //숫자를 안 뽑을 때 
    recur(num + 1, now);
 
}
 
int main()
 
{
    int T;
    cin >> T; 
    for (int tc = 1; tc <= T; tc++) {
        init();
        cin >> N >> B;
        for (int i = 0; i < N; i++) {
            cin >> height[i];
        }
 
        recur(0,0);
 
        cout << "#" << tc << " " << MIN<<"\n";
    }
 
     
 
    return 0;
}