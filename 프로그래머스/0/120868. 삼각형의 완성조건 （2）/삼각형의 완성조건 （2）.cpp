#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    int bigger = (sides[0]>sides[1])? sides[0]: sides[1];
    int sum=0; 
    for (int i=0; i<sides.size(); i++){
        sum+=sides[i];
    }
    
    int smaller=sum-bigger;
    //가장 긴변을 가지고 있을 때 
    for (int i=bigger; i>0; i--){
        if (bigger<smaller+i) {
            answer+=1;
        }
    }
    
    //나머지 한변이 가장 길 때 
    answer+=(sum-bigger-1);
    
    return answer;
}