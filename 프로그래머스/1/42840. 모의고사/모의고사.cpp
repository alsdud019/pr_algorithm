#include <string>
#include <vector>
#include <iostream>

using namespace std;

int first[]={1,2,3,4,5};
int second[]={2,1,2,3,2,4,2,5};
int third[]={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};



vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int mans[3]={0,};
    
    for (int i=0; i<answers.size(); i++){
        int a=i%5;
        if (answers[i]==first[a]){
            mans[0]++;
        }
        
        int b=i%8;
        if (answers[i]==second[b]){
            mans[1]++;
        }
        
        int c=i%10;
        if (answers[i]==third[c]){
            mans[2]++;   
        }
        
    }

    // for (int i=0; i<3; i++){
    //     cout<<mans[i]<<" ";
    // }
    answer.push_back(1);
    for (int i=1; i<3; i++){
        int num=answer.back()-1;
        
        if (mans[num]<mans[i]){
            answer.clear();
            answer.push_back(i+1);
        }
        else if (mans[num]==mans[i]){
            answer.push_back(i+1);
        }
        
    }
    

    
    return answer;
}