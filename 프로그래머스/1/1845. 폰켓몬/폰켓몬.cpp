#include <vector>
#include <set> 
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> arr;
    
    for (int i=0; i<nums.size(); i++){
        arr.insert(nums[i]);
    }
    if (arr.size()<nums.size()/2) return arr.size();
    else return nums.size()/2;
    
    // return answer;
}