#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    int mode=0;
    string ret="";
    
    for (int idx=0; idx<code.size(); idx++){
        if (!mode){
            if (code[idx]=='1'){
                mode=1;
            }
            else if (code[idx]!='1' && idx%2==0){
                ret+=code[idx];
            }
        }
        else{
            if (code[idx]=='1'){
                mode=0;
            }
            else if (code[idx]!='1' && idx%2!=0){
                ret+=code[idx];
            }
        }
    }
    if (ret.size()<1) return "EMPTY";
    
    return ret;
}