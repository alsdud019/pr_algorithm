#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    string now="";
    
    for (int j=0; j<picture.size(); j++){
        for (int i=0; i<k; i++){
            for (int n=0; n<picture[j].size(); n++){
                for (int m=0; m<k; m++){
                    now+=picture[j][n];
                }
            }
            answer.push_back(now);
            now="";
        }
    }
    


    
    return answer;
}