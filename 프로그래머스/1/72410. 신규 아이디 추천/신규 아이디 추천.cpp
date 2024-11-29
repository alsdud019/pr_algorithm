#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    string ban="~!@#$%^&*()=+[{]}:?,<>/";
    
    for (int i=0; i<new_id.size(); i++){
        //1단계
        if ('A'<= new_id[i] && new_id[i]<='Z'){
            new_id[i]=new_id[i]+32;
        }
        
        //2단계
        if (ban.find(new_id[i]) != string::npos){
            new_id.erase(i,1);
            i--;
        }
        
    }
    
    for (int i=0; i<new_id.size(); i++){
        if (new_id[i]=='.'){
            //첫번째 위치하면
            if (i==0){
                new_id.erase(i,1);
                i--;
            }
            
            //연달아 나오면
            else if (new_id[i+1]=='.'){
                new_id.erase(i+1,1);
                i--;
            }
            //마지막에 위치하면
            else if (i==new_id.size()-1){
                new_id.erase(i,1);
                i--;
            }
        }
    }
    
    //5단계
    if (new_id.size()<1){
        new_id="a";
    }
    
    if (new_id.size()>15){
        new_id=new_id.substr(0,15);
        
        if (new_id[new_id.size()-1]=='.'){
            new_id.erase(new_id.size()-1,1);
        }
    }
    
    if (new_id.size()<3){
        while(new_id.size()!=3){
            new_id+=new_id[new_id.size()-1];
        }
    }
    
    
    answer=new_id;
    
    
    return answer;
}