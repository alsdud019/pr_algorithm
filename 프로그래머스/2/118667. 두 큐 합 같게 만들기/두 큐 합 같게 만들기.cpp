#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    int answer_limit=queue1.size()*2+1;
    
    queue<int> testq1;
    queue<int> testq2;
    
    long long sum1=0;
    long long sum2=0;
    
    for (int i=0; i<queue1.size(); i++){
        testq1.push(queue1[i]);
        sum1+=queue1[i];
        
        testq2.push(queue2[i]);
        sum2+=queue2[i];
    }
    
    long long avg=(sum1+sum2)/2;
    
    
    while(!testq1.empty() && !testq2.empty()){
        
        if (sum1==avg){
            return answer;
        }
        
        if (answer_limit<answer){
            return -1;
        }
        
        if (sum1 > avg){
            
            int num=testq1.front();
            sum1-=num; 
            testq1.pop();
            
            testq2.push(num);
            sum2+=num;
           
        }
        
        else if (sum2>avg){
            int num=testq2.front();
            sum2-=num;
            testq2.pop();
            
            testq1.push(num);
            sum1+=num;
        }
        answer++;
        
    }

    return -1;
}