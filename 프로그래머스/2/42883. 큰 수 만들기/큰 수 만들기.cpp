#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx=-1;
    //number.size()-k개를 뽑을거다. 
    for (int i=0; i<number.size()-k; i++){
        char maxC=' ';
        for (int j=idx+1; j<=k+i; j++){
            if (number[j]>maxC){
                maxC=number[j];
                idx=j;
            }
        }
        answer+=maxC;
        
    }
    
    return answer;
}