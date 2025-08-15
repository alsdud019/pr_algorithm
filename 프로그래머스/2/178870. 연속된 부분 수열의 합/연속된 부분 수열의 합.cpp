#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    
    int left=0;
    int right=0;
    int sum=0;
    
    while(left<=right && right<=sequence.size()){
        
        if (sum==k){
            if (answer.empty()||(answer[1]-answer[0]>right-left )){
                answer={left, right};
                // cout<<answer[0]<<" "<<answer[1]<<'\n';
            }
            // cout<<left<<" "<<right<<'\n';
            
        }
        
        if (sum<k){
            sum+=sequence[right];
            right++;
        }
        else{
            sum-=sequence[left];
            left++;
        }
    }
    
    answer[1]-=1;
    
    return answer;
}