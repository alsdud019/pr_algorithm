#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    string no="~!@#$%^&*()=+[{]}:?,<>/";
    
    
    
    for (int i=0; i<new_id.size(); i++){
        //1단계 소문자치환
        if ('A'<=new_id[i] && new_id[i] <='Z') new_id[i]+=32;
        
        //2단계 사용가능 문자만
        if (find(no.begin(), no.end(),new_id[i])!=no.end()) {
            new_id.erase(i,1);
            i--;
        }       
    }
    
    for (int i=0; i<new_id.size(); i++){
        if(new_id[i]=='.') {
            //첫번째일때 
            if(i==0) 
            {
                new_id.erase(i,1);
                i--;}
            //연속일때
            else if (new_id[i+1]=='.'){
                new_id.erase(i+1,1);
                i--;
            }
            //마지막일때
            else if(i==new_id.size()-1){
                new_id.erase(i,1);
                i--;
            }
            
        }   
        
    }    
    
    
    //5단계
    if(new_id.size()==0) new_id='a';
    
    
    //6단계
    if (new_id.size()>15) 
    {
        new_id=new_id.substr(0,15);
        
        if (new_id[new_id.size()-1]=='.') new_id=new_id.substr(0,14);
    }
    
    //7단계
    if (new_id.size()<3) 
    {
        
        while (new_id.size()<3){
            
            new_id+=new_id[new_id.size()-1];
        }
    }
    
    
    cout<<new_id<<endl;
    
    
    return new_id;
}