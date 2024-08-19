#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    // s="1zerotwozero3";
    int answer = 0;  
    string ans="";
    string numbers[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    
    for (int i=0; i<s.size(); i++){
        if ('0'<=s[i] && s[i]<='9'){
            ans+=s[i];
            // s.erase(0,1);
        }
        else {
            for (int j=0; j<10; j++){
                if (s.find(numbers[j])!=string::npos) {
                    int idx=s.find(numbers[j]);
                    s[idx]=j+'0';
                    s.erase(idx+1, numbers[j].size()-1);
                }
            }  
            
        }
         
    }
    // cout<<<<endl;
    // cout<<ans<<endl;
    return stoi(s);
}