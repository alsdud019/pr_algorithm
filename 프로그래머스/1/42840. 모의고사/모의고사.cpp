#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector <int> a={1,2,3,4,5};
vector <int> b={2,1,2,3,2,4,2,5};
vector <int> c={3,3,1,1,2,2,4,4,5,5};

int DAT[3];
int max_idx;
int MAX=0;



vector<int> solution(vector<int> answers) {
    vector<int> answer;
    for (int i=0; i<answers.size(); i++){
        int a_mok=i%a.size();
        if (answers[i]==a[a_mok]){
            DAT[0]++;
        }
        int b_mok=i%b.size();
        if (answers[i]==b[b_mok]){
            DAT[1]++;
        }
        int c_mok=i%c.size();
        if (answers[i]==c[c_mok]){
            DAT[2]++;
        }
    }
    for (int j=0; j<3; j++){
        if (MAX<DAT[j]){
            answer.clear();
            answer.push_back(j+1);
            MAX=DAT[j];
        }
        else if(MAX==DAT[j]){
            answer.push_back(j+1);
        }
    }
    
    
    
    return answer;
}