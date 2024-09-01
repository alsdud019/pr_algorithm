#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum=brown+yellow;
    int row=-1;
    int col=-1;
    for (int i=2; i<=sum/2; i++){
        if (sum%i==0){
            // cout<<i<<endl;
            int mok=sum/i;
            int gop=(i-2)*(mok-2);
            // cout<<gop<<endl;
            if (gop==yellow) {
                cout<<gop<<endl;
                row= i>mok? i:mok;
                col=sum/row;
                break;
            }
        }
    }
    // cout<<row<< " "<<col<<endl;
    return {row,col};
}