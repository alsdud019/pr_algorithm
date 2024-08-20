#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for (int i=0; i<s.size(); i++){
        
        int cnt=0;
        while(cnt<index){
            s[i]+=1;
            if (s[i]>'z') s[i]=s[i]%123+'a';
            
            if (skip.find(s[i])!=string::npos) continue;
            else {
                cnt++;
            }
        }
        
        
    }
    return s;
}