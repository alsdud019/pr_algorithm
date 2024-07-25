#include <string>
#include <vector>
#include <iostream>

using namespace std;


string convert(string str, int num){
    for (int i=0; i<num; i++){
        str=str[str.size()-1]+str.substr(0,str.size()-1);
    }
    return str;
    
}

int solution(string A, string B) {
    int answer = 0;
    
    for (int i=0; i<A.size(); i++){
        if (convert(A,i)==B) return i;
    }
    
    return -1;
    
    
    
    // return answer;
}