#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int DAT[1001]={0};
    
    for (int i=0; i<array.size(); i++){
        DAT[array[i]]+=1;
    }
    
    int max=-9999;
    int flag=0;
    for(int i=0; i<1001; i++){
        if (DAT[i]>max) {
            max=DAT[i];
            answer=i;
            flag=0;}
        
        else if (DAT[i]==max){
            flag=1;
        }
    }
    if (flag) return -1;
    return answer;
}