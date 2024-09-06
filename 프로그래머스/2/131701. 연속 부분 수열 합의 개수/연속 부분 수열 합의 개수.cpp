#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    vector<int> vec=elements;
    set<int> s;
    
    vec.insert(vec.end(), elements.begin(), elements.end());
    
    for (int i=0; i<elements.size(); i++){
        for (int k=0; k<elements.size()-1; k++){
            vector<int> arr(vec.begin()+i, vec.begin()+i+k+1);
            int sum=0;
            for (int a: arr){
                // cout<<a<<" ";
                sum+=a;
            }
            // cout<<sum<<endl;
            s.insert(sum);
        }
       
    }
    // cout<<s.size();
    return s.size()+1;
}