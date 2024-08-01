#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i=0; i<s.size(); i++){
        if (s[i]==' ') continue;
        if ('A'<=s[i] && s[i]<='Z') {
            s[i]=(s[i]+n)%65%26+65;
            continue;}
        
        else if ('a'<=s[i] && s[i]<='z') 
        {
            s[i]=(s[i]+n)%97%26+97;
            continue;}
        
        s[i]+=n;
        
    }
    return s;
}