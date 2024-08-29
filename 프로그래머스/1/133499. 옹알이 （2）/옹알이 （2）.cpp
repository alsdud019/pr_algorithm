#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (auto babble:babbling){
        int i=0; 
        int flag=0;
        while(i<babble.size()){
            if (string(babble, i, 3)=="aya" && flag!=1 ){i+=3; flag=1;}
            else if (string(babble, i,2)=="ye"&& flag!=2){i+=2; flag=2;}
            else if (string(babble, i, 3)=="woo"&& flag!=3){i+=3; flag=3;}
            else if (string(babble, i, 2)=="ma"&& flag!=4){i+=2; flag=4;}
            else {flag=0; break;}
        }
        
        if (flag!=0) answer++;
    }
    
    

    return answer;
}